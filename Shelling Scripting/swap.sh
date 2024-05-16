#Write a shell script to exchange two variables and show their value on the screen
echo "Num1: "
read  num1
echo "Num2: "
read num2

echo "before swapping"
echo "$num1 $num2"

echo "After Swapping"
temp=$num1
num1=$num2
num2=$temp
echo "$num1 $num2"

