#!/bin/bash

# Initialize the output file
output_file="statistics/users_with_more_than_5_points.txt"
echo "" > "$output_file"

# Loop through all shortData JSON files
for filepath in ./shortData/Wolfsburg.json; do
  # Extract campus name from filepath
  campus_name=$(basename "$filepath" .json)

  # Initialize an array to hold users with more than 5 points
  declare -a users_array=()

  # Read the JSON file and filter users
  while read -r line; do
    points_this_student=$(echo "$line" | jq -r '.correction_point')
    user_this_student=$(echo "$line" | jq -r '.login')
is_active=$(echo "$line" | jq -r '."active?"')

    if [ "$points_this_student" -ge 5 ] && [ "$is_active" = "true" ]; then
      users_array+=("$points_this_student $user_this_student")
    fi
  done < <(jq -c '.[][]' "$filepath")

  # Sort the array in descending order of points
  IFS=$'\n' sorted_users_array=($(sort -k1,1nr <<< "${users_array[*]}"))
  unset IFS

  # Append to the output file
  echo "$campus_name:" >> "$output_file"
  for i in "${sorted_users_array[@]}"; do
    points=$(echo "$i" | awk '{print $1}')
    user=$(echo "$i" | awk '{print $2}')
    echo -e "\t$user:$points" >> "$output_file"
  done

  # Terminal output for progress tracking
  echo "Processed campus: $campus_name"
done

# Terminal output for completion
echo "Users with more than 5 correction points for each campus have been calculated and saved in $output_file."
