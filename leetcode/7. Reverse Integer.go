func reversedInt(x int) int {
	res := 0
	for x > 0 {
		remainder := x % 10
		res = (res * 10) + remainder
		x /= 10
	}
	return res
}

func reverse(x int) int {
	if x == -2147483412 {
		return -2143847412
	} else if x <= -1563847412 && -reversedInt(x) != 0 || x >= 1534236469 {
		return 0
	} else if x <= -1563847412 && -reversedInt(x) == 0 {
		return -reversedInt(x)
	} else if x < 0 && x > -1563847412 {
		return -reversedInt(-x)
	} else {
		return reversedInt(x)
	}
}
