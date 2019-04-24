#!/bin/bash

x=10
y=5

let sum=$x+$y
diff=$(($x - $y))
let mul=$x*$y
let div=$x/$y
let mod=$x%$y
let exp=$x**$y

echo "$x + $y = $sum"
echo "$x - $y = $diff"
echo "$x * $y = $mul"
echo "$x / $y = $div"
echo "$x % $y = $mod"
echo "$x ** $y = $exp"
exit
