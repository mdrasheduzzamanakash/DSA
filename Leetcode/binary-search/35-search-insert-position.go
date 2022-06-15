func searchInsert(nums []int, target int) int {
	lo := 0
	hi := len(nums) - 1

	for lo <= hi {
		mid := lo + (hi-lo)/2

		if target < nums[mid] {
			hi = mid - 1
		} else if target > nums[mid] {
			lo = mid + 1
		} else {
			return mid
		}
	}

	return lo
}
