#!/bin/sh

awk -F '' '{ print substr($0, 13)}'
