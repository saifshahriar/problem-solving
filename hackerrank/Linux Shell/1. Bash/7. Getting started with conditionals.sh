#!/bin/sh

read -r char

[ "$char" = 'Y' ] || [ "$char" = 'y' ] && echo "YES" || echo "NO"