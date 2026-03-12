#!/bin/bash

count=1
echo "sno | name | date"
for file in *
do
    if [ -f "$file" ]
    then
		credate=$(stat -c %w "$file")
		if [ "$credate" = "-" ]
		then
			credate=$(stat -c %y "$file" | cut -d" " -f1)
		fi
		echo "$count | $(basename "$file") | $credate"
		((count++))
		fi	
done
