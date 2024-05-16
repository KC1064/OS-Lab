#!/bin/bash

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Initialize sum variable to store the sum of digits
sum=0

# Loop through each digit of the number
while [ $number -gt 0 ]; do
    # Extract the last digit
    digit=$((number % 10))
    # Add the digit to the sum
    sum=$((sum + digit))
    # Remove the last digit from the number
    number=$((number / 10))
done

# Display the sum of digits
echo "Sum of digits: $sum"
