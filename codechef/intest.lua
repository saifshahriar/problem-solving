#!/usr/bin/env lua

local n, k = io.read("*number", "*number")
local count = 0

for _ = 1, n do
	local num = io.read("*number")
	if num % k == 0 then
		count = count + 1
	end
end

print(count)

-- https://www.codechef.com/problems/intest
