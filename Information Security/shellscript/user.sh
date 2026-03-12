#!/bin/bash

echo "Enter User: "
read user

while true
do
	if who | grep -w "$user">/dev/null
	then
		echo "User '$user' has logged"
	else
		echo "not logged in trying in 30 sec"
		sleep 5
	fi
done
