#!/bin/bash

# Prompt the user to enter a number
echo "Enter the number:"
read num

fact=1

# Calculate factorial
for ((i = 1; i <= num; i++)); do
    fact=$((fact * i))
done

# Display the factorial
echo "Factorial of $num is $fact"
