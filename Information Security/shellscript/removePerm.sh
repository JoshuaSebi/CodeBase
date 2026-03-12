#!/bin/bash

echo "Enter file"
read file

if [ -f "$file" ]
then
	chmod a-x "$file"
else 
	echo "Not found"
fi
