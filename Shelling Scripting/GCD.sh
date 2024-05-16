#!/bin/bash

# Function to find the GCD of two numbers
gcd() {
    local num1=$1
    local num2=$2
    while [ $num2 -ne 0 ]; do
        local remainder=$((num1 % num2))
        num1=$num2
        num2=$remainder
    done
    echo "$num1"
}

# Prompt the user to enter two numbers
echo "Enter the first number:"
read number1
echo "Enter the second number:"
read number2

# Calculate the GCD of the two numbers
result=$(gcd $number1 $number2)

# Display the GCD
echo "GCD of $number1 and $number2 is: $result"
