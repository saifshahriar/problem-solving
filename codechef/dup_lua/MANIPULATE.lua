#!/usr/bin/env lua

local t = tonumber(io.read())

for _ = 1, t do
	local x, y = io.read("*number", "*number")
	print(x >= y and "YES" or "NO")
end