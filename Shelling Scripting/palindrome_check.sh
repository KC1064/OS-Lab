# Function to check if a string is a palindrome
is_palindrome() {
    local input="$1"
    local reversed_input=$(echo "$input" | rev)
    if [ "$input" = "$reversed_input" ]; then
        echo "The string '$input' is a palindrome."
    else
        echo "The string '$input' is not a palindrome."
    fi
}

# Prompt the user to enter a string
echo "Enter a string:"
read input_string

# Call the function to check if the string is a palindrome
is_palindrome "$input_string"
