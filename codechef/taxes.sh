#!/bin/sh

read -r t

for i in $(seq 1 "$t"); do
	read -r x
	[ "$x" -gt 100  ] && echo $((x-10)) || echo "$x"
done

# https://www.codechef.com/problems/taxes 
