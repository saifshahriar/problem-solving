#!/usr/bin/env

local t = tonumber(io.read())

for _ = 1, t do
	local n, m, k = io.read("*number", "*number", "*number")
	print(m - k >= n and "YES" or "NO")
end

-- https://www.codechef.com/problems/coursereg 
