func reverseArr(s []int) []int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func removeIndex(s []int, index int) []int {
	return append(s[:index], s[index+1:]...)
}

func rotate(nums []int, k int) []int {
	for i := 1; i <= k; i++ {
		// nums = [1,2,3,4,5,6,7]
		n := nums[len(nums)-1]
		// pop 7 from the list -> [1,2,3,4,5,6]
		nums = removeIndex(nums, len(nums)-1)
		// reverse -> [6, 5, 4, 3, 2, 1]
		nums = reverseArr(nums)
		// append 7 -> [6, 5, 4, 3, 2, 1, 7]
		nums = append(nums, n)
		// reverse -> [1,2,3,4,5,6,7]
		nums = reverseArr(nums)
	}
}
