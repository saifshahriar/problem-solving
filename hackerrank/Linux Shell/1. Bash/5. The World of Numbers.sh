#!/bin/sh

read x
read y

expr $x + $y
expr $x - $y
echo $[x*y]
echo $[x/y]