#!/usr/bin/env lua

function miniMaxSum(arr)
    local min, max = 0, 0
    table.sort(arr)
    for i = 1, #arr - 1 do
        min = min + arr[i]
    end
    for i = 2, #arr do
        max = max + arr[i]
    end
    print(min..' '..max)
end

local arr = {}

for token in string.gmatch(io.stdin:read("*l"):gsub("%s+$", ""), "[^%s]+") do
    table.insert(arr, tonumber(token))
end

miniMaxSum(arr)