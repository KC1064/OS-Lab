#!/bin/bash

read -p "Enter a five-digit number: " number

if ! [[ $number =~ ^[0-9]{5}$ ]]; then
    echo "Error: Please enter a five-digit number."
    exit 1
fi

echo "Digits in odd positions are:"
echo ${number:0:1} # 1st digit
echo ${number:2:1} # 3rd digit
echo ${number:4:1} # 5th digit
