#!/usr/bin/env python3
# -*- coding: utf-8 -*-

english = input().lower()  # >>> nevermind its me

split_english = english.split(' ')  # >>> ['nevermind', 'its', 'me']

pig_latin = []

for i in range(0, len(split_english)):  # Range is 0 to length of split_english

	list_english = list(split_english[i])  # List of every word from the split_english array

	# Output:
	# ['n', 'e', 'v', 'e', 'r', 'm', 'i', 'n', 'd']
	# ['i', 't', 's']
	# ['m', 'e']

	x = [list_english[0], 'ay', ' ']  # Adds "ay" and a space after the list_english[0]/initial letter

	# Output:
	# ['n', 'ay', ' ']
	# ['i', 'ay', ' ']
	# ['m', 'ay', ' ']

	list_english[0] = ''  # Changes the value of the initial letter to ""/null

	# print(list_english)
	#
	# Output:
	# ['', 'e', 'v', 'e', 'r', 'm', 'i', 'n', 'd']
	# ['', 't', 's']
	# ['', 'e']

	list_english.remove('')  # Removes the first/null item

	# print(list_english)
	#
	# Output:
	# ['e', 'v', 'e', 'r', 'm', 'i', 'n', 'd']
	# ['t', 's']
	# ['e']

	pig_latin += list_english + x  # Joins indexes from the loop and adds "ay "(var x) after every indexes

	# ['e', 'v', 'e', 'r', 'm', 'i', 'n', 'd', 'n', 'ay', ' ', 't', 's', 'i', 'ay', ' ', 'e', 'm', 'ay', ' ']

pig_latin = ''.join(pig_latin)  # Joins the list/array as a string

# evermindnay tsiay emay

print(pig_latin)  # Prints the output
