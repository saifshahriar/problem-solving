#!/usr/bin/env lua

function timeConversion(s)
	local sub = string.sub
	local int, str = tonumber, tostring

	if sub(s, -2, -2) == 'P' and sub(s, 1, 2) ~= '12' then
		s = str(12 + int(sub(s, 1,2))) .. sub(s, 3, 8)
		return s
	elseif sub(s, -2, -2) == 'A' and sub(s, 1, 2) == '12' then
		s = '00' .. sub(s, 3, 8)
		return s
	else
		return sub(s, 1, 8)
	end
end

local fptr   = io.open(os.getenv("OUTPUT_PATH"), "w")
local s      = io.stdin:read("*l")
local result = timeConversion(s)

fptr:write(result, "\n")
fptr:close()