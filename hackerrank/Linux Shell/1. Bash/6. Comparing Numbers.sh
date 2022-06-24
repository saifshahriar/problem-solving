#!/bin/sh

read x
read y

[ $x -eq $y ] && echo X is equal to Y || ([ $x -lt $y ] && echo X is less than Y || echo X is greater than Y)