#!/bin/bash

# Initialize variables for overall statistics
all_students=0
all_points=0
all_above_avg=0
all_below_one=0
all_active_students=0
all_active_points=0
all_active_above_avg=0
all_active_below_one=0
all_inactive_students=0
all_inactive_points=0
all_inactive_above_avg=0
all_inactive_below_one=0

# Initialize the output file
output_file="statistics/statistics.txt"
echo "" > "$output_file"

# Loop through all shortData JSON files
for filepath in ./shortData/*.json; do
  # Extract campus name from filepath
  campus_name=$(basename "$filepath" .json)

  # Initialize variables for this campus
  students=0
  points=0
  above_avg=0
  below_one=0
  active_students=0
  active_points=0
  active_above_avg=0
  active_below_one=0
  inactive_students=0
  inactive_points=0
  inactive_above_avg=0
  inactive_below_one=0

  # Read the JSON file and calculate statistics
  while read -r line; do
    points_this_student=$(echo "$line" | jq -r '.correction_point')
    is_active=$(echo "$line" | jq -r '."active?"')

    ((students++))
    ((points += points_this_student))

    if [ "$is_active" == "true" ]; then
      ((active_students++))
      ((active_points += points_this_student))
    else
      ((inactive_students++))
      ((inactive_points += points_this_student))
    fi
  done < <(jq -c '.[][]' "$filepath")

  # Calculate averages
  [ $students -gt 0 ] && avg=$(awk "BEGIN {printf \"%.1f\", $points/$students}") || avg=0
  [ $active_students -gt 0 ] && avg_active=$(awk "BEGIN {printf \"%.1f\", $active_points/$active_students}") || avg_active=0
  [ $inactive_students -gt 0 ] && avg_inactive=$(awk "BEGIN {printf \"%.1f\", $inactive_points/$inactive_students}") || avg_inactive=0

  # Count students above average and below one point
  while read -r line; do
    points_this_student=$(echo "$line" | jq -r '.correction_point')
    is_active=$(echo "$line" | jq -r '."active?"')

    [ $(awk "BEGIN {print ($points_this_student > $avg)}") -eq 1 ] && ((above_avg++))
    [ $(awk "BEGIN {print ($points_this_student < 1)}") -eq 1 ] && ((below_one++))

    if [ "$is_active" == "true" ]; then
      [ $(awk "BEGIN {print ($points_this_student > $avg_active)}") -eq 1 ] && ((active_above_avg++))
      [ $(awk "BEGIN {print ($points_this_student < 1)}") -eq 1 ] && ((active_below_one++))
    else
      [ $(awk "BEGIN {print ($points_this_student > $avg_inactive)}") -eq 1 ] && ((inactive_above_avg++))
      [ $(awk "BEGIN {print ($points_this_student < 1)}") -eq 1 ] && ((inactive_below_one++))
    fi
  done < <(jq -c '.[][]' "$filepath")

  # Append to the output file
  echo "$campus_name:" >> "$output_file"
  echo -e "\tAll Students:" >> "$output_file"
  echo -e "\t\tStudents: $students" >> "$output_file"
  echo -e "\t\tCorrection Points: $points" >> "$output_file"
  echo -e "\t\tAverage Points per Student: $avg" >> "$output_file"
  echo -e "\t\tStudents with more than Average Points: $above_avg" >> "$output_file"
  echo -e "\t\tStudents with less than one Point: $below_one" >> "$output_file"

  echo -e "\tActive Students:" >> "$output_file"
  echo -e "\t\tStudents: $active_students" >> "$output_file"
  echo -e "\t\tCorrection Points: $active_points" >> "$output_file"
  echo -e "\t\tAverage Points per Active Student: $avg_active" >> "$output_file"
  echo -e "\t\tStudents with more than Average Points: $active_above_avg" >> "$output_file"
  echo -e "\t\tStudents with less than one Point: $active_below_one" >> "$output_file"

  echo -e "\tInactive Students:" >> "$output_file"
  echo -e "\t\tStudents: $inactive_students" >> "$output_file"
  echo -e "\t\tCorrection Points: $inactive_points" >> "$output_file"
  echo -e "\t\tAverage Points per Inactive Student: $avg_inactive" >> "$output_file"
  echo -e "\t\tStudents with more than Average Points: $inactive_above_avg" >> "$output_file"
  echo -e "\t\tStudents with less than one Point: $inactive_below_one" >> "$output_file"

  # Terminal output for progress tracking
  echo "Statistics for $campus_name have been calculated."

  # Update overall statistics
  ((all_students += students))
  ((all_points += points))
  ((all_above_avg += above_avg))
  ((all_below_one += below_one))
  ((all_active_students += active_students))
  ((all_active_points += active_points))
  ((all_active_above_avg += active_above_avg))
  ((all_active_below_one += active_below_one))
  ((all_inactive_students += inactive_students))
  ((all_inactive_points += inactive_points))
  ((all_inactive_above_avg += inactive_above_avg))
  ((all_inactive_below_one += inactive_below_one))
done

# Calculate overall averages
[ $all_students -gt 0 ] && all_avg=$(awk "BEGIN {printf \"%.1f\", $all_points/$all_students}") || all_avg=0
[ $all_active_students -gt 0 ] && all_avg_active=$(awk "BEGIN {printf \"%.1f\", $all_active_points/$all_active_students}") || all_avg_active=0
[ $all_inactive_students -gt 0 ] && all_avg_inactive=$(awk "BEGIN {printf \"%.1f\", $all_inactive_points/$all_inactive_students}") || all_avg_inactive=0

# Append overall statistics to the output file
echo "All Campuses:" >> "$output_file"
echo -e "\tAll Students:" >> "$output_file"
echo -e "\t\tStudents: $all_students" >> "$output_file"
echo -e "\t\tCorrection Points: $all_points" >> "$output_file"
echo -e "\t\tAverage Points per Student: $all_avg" >> "$output_file"
echo -e "\t\tStudents with more than Average Points: $all_above_avg" >> "$output_file"
echo -e "\t\tStudents with less than one Point: $all_below_one" >> "$output_file"

echo -e "\tActive Students:" >> "$output_file"
echo -e "\t\tStudents: $all_active_students" >> "$output_file"
echo -e "\t\tCorrection Points: $all_active_points" >> "$output_file"
echo -e "\t\tAverage Points per Active Student: $all_avg_active" >> "$output_file"
echo -e "\t\tStudents with more than Average Points: $all_active_above_avg" >> "$output_file"
echo -e "\t\tStudents with less than one Point: $all_active_below_one" >> "$output_file"

echo -e "\tInactive Students:" >> "$output_file"
echo -e "\t\tStudents: $all_inactive_students" >> "$output_file"
echo -e "\t\tCorrection Points: $all_inactive_points" >> "$output_file"
echo -e "\t\tAverage Points per Inactive Student: $all_avg_inactive" >> "$output_file"
echo -e "\t\tStudents with more than Average Points: $all_inactive_above_avg" >> "$output_file"
echo -e "\t\tStudents with less than one Point: $all_inactive_below_one" >> "$output_file"

# Terminal output for completion
echo "Statistics for all campuses have been calculated and saved in $output_file."
