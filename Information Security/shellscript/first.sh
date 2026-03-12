#!/bin/bash

dir="."
count=1

echo "Sno  |  Name  |  Date  "
echo "______________________"

for file in "$dir"/*
do
    if [ -f "$file" ]
    then 
        credate=$(stat -c %w "$file") 
        if [ "$credate" = "-" ]
        then
            credate=$(stat -c %y "$file" | cut -d" " -f1)
        fi
        echo "$count | $(basename "$file") | $credate"
        count=$((count+1))
    fi
done