#!/usr/bin/env lua

local case = tonumber(io.read())

for _ = 1, case do
	local a, b = io.read("*number", "*number")
	if a < b then
		print "FIRST"
	elseif a > b then
		print "SECOND"
	else
		print "ANY"
	end
end

-- https://www.codechef.com/problems/cabs
