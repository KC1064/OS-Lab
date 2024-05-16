#!/bin/bash

# Prompt the user to enter the string and the substring
echo "Enter a string:"
read string
echo "Enter a substring to search:"
read substring

# Find the position of the substring in the string
position=$(awk 'BEGIN{print index("'"$string"'", "'"$substring"'")}')
if [ "$position" -eq 0 ]; then
    echo "Substring '$substring' not found in string '$string'"
else
    echo "Position of substring '$substring' in string '$string': $position"
fi

