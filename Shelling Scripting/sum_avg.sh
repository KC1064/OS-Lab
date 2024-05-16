echo "Number 1: "
read num1;
echo "Number 2: "
read num2;
echo "Number 3: "
read num3;
echo "Number 4: "
read num4;

sum=$((num1 + num2 + num3 + num4));

avg=$((sum/4));
echo "Sum: $sum";
echo "Average: $avg";
