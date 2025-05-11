#!/bin/bash

current_hour=$(date +%H)

current_hour=$((10#$current_hour))

if [ $current_hour -ge 5 ] && [ $current_hour -lt 12 ]; then
    echo "Good morning!"
elif [ $current_hour -ge 12 ] && [ $current_hour -lt 18 ]; then
    echo "Good afternoon!"
else
    echo "Good night!"
fi

