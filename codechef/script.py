#!/usr/bin/env python3

import os

rootlink = "https://www.codechef.com/problems/"

rm = ["a.out", "a.o"]

for i in rm:
    if os.path.exists(i):
        os.remove(i)

for i in os.listdir():
    j = i.split(".")

    if len(j) != 2 or i == "script.py":
        continue

    match j[1]:
        case "c":
            comment_opening = "/* "
            comment_closing = " */"
        case "lua":
            comment_opening = "-- "
            comment_closing = ""
        case _:
            comment_opening = "# "
            comment_closing = ""

    # First open in reading mode to see if the comment has already added or not
    f = open(i, "r")
    if comment_opening in f.readlines()[-1]:
        f.close()
        continue
    f.close()

    f = open(i, "a")
    f.write("\n{}{}{}{}".format(comment_opening, rootlink, j[0], comment_closing))
    f.close()
