#!/usr/bin/env lua	
	
local t = tonumber(io.read())	
	
for _ = 1, t do	
	local a, b = io.read("*number", "*number")	
	print(a + b)	
end

-- https://www.codechef.com/problems/flow001	
