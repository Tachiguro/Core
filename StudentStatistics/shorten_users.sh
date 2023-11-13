# Step 1: Sort the IDs in descending order and store them in a variable
sorted_ids=$(jq -r '.[] | .id' Data/campuses.json | sort -rn)

# Step 2: Loop through each ID
for id in $sorted_ids; do
  # Get campus name corresponding to this id
  campus_name=$(jq -r --argjson id "$id" '.[] | select(.id == $id) | .name' Data/campuses.json)

  # Define the path for the filtered file
  filtered_file="shortData/${campus_name}.json"

  # Check if the filtered file does not exist
  if [ ! -f "$filtered_file" ]; then
    # Step 3: Run jq command to filter the JSON file
    jq -c '[.[] | map({id, login, usual_full_name, "staff?": ."staff?", correction_point, "active?": ."active?"})]' "Data/$campus_name.json" > "$filtered_file"
  fi
done
