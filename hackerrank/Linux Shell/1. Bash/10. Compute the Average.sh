#!/bin/sh

read -r n

for i in `seq 1 $n`; do
	read -r l
	sum=$(($sum+$l))
done

printf "%.3f" $(echo $sum/$n | bc -l)
