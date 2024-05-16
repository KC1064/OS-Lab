#!/bin/bash

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Reverse the digits of the number
reversed_number=$(echo $number | rev)

# Display the reversed number
echo "Reversed number: $reversed_number"
