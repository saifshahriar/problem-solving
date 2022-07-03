#!/usr/bin/env lua

function compareTriplets(a, b)
	arr = {0, 0}
	for i = 1, #a do
		if a[i] > b[i] then
			arr[1] = arr[1] + 1
		elseif a[i] < b[i] then
			arr[2] = arr[2] + 1
		end
	end
	return arr
end

local fptr = io.open(os.getenv("OUTPUT_PATH"), "w")
local a    = {}

for token in string.gmatch(io.stdin:read("*l"):gsub("%s+$", ""), "[^%s]+") do
	table.insert(a, tonumber(token))
end

local b = {}

for token in string.gmatch(io.stdin:read("*l"):gsub("%s+$", ""), "[^%s]+") do
	table.insert(b, tonumber(token))
end

local result = compareTriplets(a, b)

fptr:write(table.concat(result, " "))
fptr:write("\n")
fptr:close()