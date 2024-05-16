calculate_sum() {
    local n=$1
    local sum=0
    for ((i = 1; i <= n; i++)); do
        fraction=$(echo "scale=10; 1/$i" | bc)
        sum=$(echo "scale=10; $sum + $fraction" | bc)
    done
    echo $sum
}

# Prompt the user to enter the value of n
echo "Enter the value of n:"
read n

# Call the function to calculate the sum of the series
result=$(calculate_sum $n)

# Display the result
echo "Sum of the series for n=$n is: $result"
