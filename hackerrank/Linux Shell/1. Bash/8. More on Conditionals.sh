#!/bin/sh

read -r x
read -r y
read -r z

if [ $x -eq $y ] && [ $y -eq $z ]; then
	echo "EQUILATERAL"
elif [ $x -eq $y ] || [ $y -eq $z ] || [ $z -eq $y ]; then
	echo "ISOSCELES"
else
	echo "SCALENE"
fi