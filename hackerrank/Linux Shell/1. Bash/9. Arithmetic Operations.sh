#!/bin/sh

read -r num
printf "%.3f" $(echo $num | bc -l)