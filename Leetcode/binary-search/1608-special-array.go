func specialArray(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	lo, hi := 0, 1000
	for lo <= hi {
		target := lo + (hi-lo)/2
		j := lowerBound(nums, target)
		if target < n-j {
			lo = target + 1
		} else if target > n-j {
			hi = target - 1
		} else {
			return target
		}
	}
	return -1
}

func lowerBound(nums []int, target int) int {
	lo, hi := 0, len(nums)-1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if target > nums[mid] {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return lo
}

// Time Complexity: O(log(N+M))
//     Where N = 1000, M = #elements in the array
