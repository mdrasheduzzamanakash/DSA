func checkIfExist(arr []int) bool {
	nums := map[int]bool{}

	for _, val := range arr {
		if _, ok := nums[2*val]; ok {
			return true
		}
		if _, ok := nums[val/2]; ok && val%2 == 0 {
			return true
		}
		nums[val] = true
	}
	return false
}

// Time Complexity: O(N), where N = number of elements in the array
// We can also solve this problem with binary search in O(NlogN) time.
