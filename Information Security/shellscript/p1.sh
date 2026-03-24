#!/bin/bash

echo "Enter file"
read fname

if [ ! -f "$fname" ]; then
	echo "Non Existent"
	exit 1
fi

hashf="$fname.hash"
if [ ! -f "$hashf" ]; then
	sha256sum "$fname">"$hashf"
	echo "Hashed"
else 
	sha256sum -c "$hashf"
fi
