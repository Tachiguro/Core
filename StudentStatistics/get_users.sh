#!/bin/bash

ACCESS_TOKEN=$(curl -s -X POST "https://api.intra.42.fr/oauth/token" -d "grant_type=client_credentials" -d "client_id=u-s4t2ud-9c784aaf2e7e1b4dcd93699aa870d95a411438ae45f2e70d1a8b11058e3a92f8" -d "client_secret=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" | jq -r '.access_token')
echo "Access Token: $ACCESS_TOKEN"

# Initialize pagination parameters
page=1
per_page=100  # Max allowed value as per API docs

# Remove existing Data/campuses.json file if it exists
rm -f Data/campuses.json

# Initialize a variable to control the appending of commas between pages
first_page=true

# Loop to fetch all pages
while true; do
  # Fetch the current page
  response=$(curl -s -H "Authorization: Bearer $ACCESS_TOKEN" \
  "https://api.intra.42.fr/v2/campus?page=${page}&per_page=${per_page}")

  # Check if the response is empty or '[]'
  if [ -z "$response" ] || [ "$response" == "[]" ]; then
    echo "No more campuses to fetch."
    break
  fi

  # If this is not the first page, prepend a comma
  if [ "$first_page" = false ]; then
    echo -n "," >> Data/campuses.json
  fi

  # Append the filtered response to Data/campuses.json
  echo -n "$(echo $response | jq 'map({id: .id, name: .name})')" >> Data/campuses.json

  # Update the first_page flag
  first_page=false

  # Increment the page number
  ((page++))
done

echo "Campus data has been saved to Data/campuses.json."

# Initialize pagination parameters for campus
page=1
per_page=100  # Max allowed value as per API docs

# Fetch all campuses and save to an array
jq -c '.[]' Data/campuses.json | while read -r campus; do
  campus_id=$(echo "$campus" | jq -r '.id')
  campus_name=$(echo "$campus" | jq -r '.name')

  json_file_path="Data/$campus_name.json"

  # Check if the JSON file already exists
  if [ -f "$json_file_path" ]; then
    echo "JSON file for campus $campus_name already exists. Skipping API request."
    continue
  fi


  # Initialize variables for user pagination
  page=1

  # Remove existing Data/$campus_name.json file if it exists
  rm -f "$json_file_path"

  # Start the JSON array
  echo "[" > "$json_file_path"

  # Initialize a variable to control the appending of commas between pages
  first_page=true

  # Loop to fetch all pages of users for the current campus
  while true; do
    # Fetch the current page
    response=$(curl -s -H "Authorization: Bearer $ACCESS_TOKEN" \
    "https://api.intra.42.fr/v2/campus/$campus_id/users?page=${page}&per_page=${per_page}")

    # Check if the response is empty or '[]'
    if [ -z "$response" ] || [ "$response" == "[]" ]; then
      echo "No more users to fetch for campus $campus_name."
      break
    fi

    # If this is not the first page, prepend a comma
    if [ "$first_page" = false ]; then
      echo -n "," >> "Data/$campus_name.json"
    fi

    # Append the response to Data/$campus_name.json
    echo -n "$response" >> "Data/$campus_name.json"

    # Update the first_page flag
    first_page=false

    # Increment the page number
    ((page++))
    sleep 0.5
  done

  # End the JSON array
  echo "]" >> "$json_file_path"

  echo "User data for campus $campus_name has been saved to Data/$campus_name.json."
done
