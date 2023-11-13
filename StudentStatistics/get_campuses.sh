#!/bin/bash
# Tachi ò_ó has codes this

ACCESS_TOKEN=$(curl -X POST "https://api.intra.42.fr/oauth/token" -d "grant_type=client_credentials" -d "client_id=u-s4t2ud-9c784aaf2e7e1b4dcd93699aa870d95a411438ae45f2e70d1a8b11058e3a92f8" -d "client_secret=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" | jq -r '.access_token')

if [[ "$ACCESS_TOKEN" != "null" ]]; then
	echo "Deleting Data/campuses.json"
	rm -f Data/campuses.json
else
	echo "Invalid ACCESS_TOKEN=$ACCESS_TOKEN. Exiting script."
	exit 1
fi


page=1
per_page=100  # Max allowed values
first_page=true

while true; do
	response=$(curl -s -H "Authorization: Bearer $ACCESS_TOKEN" \
	"https://api.intra.42.fr/v2/campus?page=${page}&per_page=${per_page}")

	# Check if the response is empty or '[]'
	if [ -z "$response" ] || [ "$response" == "[]" ]; then
		echo "No more campuses."
		break
	fi

	# If this is not the first page insert a comma
	if [ "$first_page" = false ]; then
		echo -n "," >> Data/campuses.json
	fi

	echo -n "$(echo $response | jq 'map({id: .id, name: .name})')" >> Data/campuses.json

	first_page=false
	((page++))
done

echo "Campus data has been saved to Data/campuses.json."
