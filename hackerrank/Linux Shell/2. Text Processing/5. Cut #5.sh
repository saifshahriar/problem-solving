#!/bin/sh

awk -F '\t' '{ print $1"\t"$2"\t"$3 }'