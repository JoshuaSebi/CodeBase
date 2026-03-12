#!/bin/bash

echo "Fname"
read fname

if [ ! -f "$fname" ]; then
	echo "ERROR"
	exit 1
fi 

hashfile="$fname.hash"

if [ ! -f "$hashfile" ]
then 
	sha256sum "$fname" > "$hashfile"
	echo "Created"
else 
	sha256sum -c "$hashfile"
fi
