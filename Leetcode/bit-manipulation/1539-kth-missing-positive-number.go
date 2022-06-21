func findKthPositive(arr []int, k int) int {
	guess := 0
	for k > 0 {
		guess++
		if isMissing(arr, guess) {
			k--
		}
	}
	return guess
}

func isMissing(arr []int, target int) bool {
	lo, hi := 0, len(arr)-1

	for lo <= hi {
		mid := lo + (hi-lo)/2
		if target < arr[mid] {
			hi = mid - 1
		} else if target > arr[mid] {
			lo = mid + 1
		} else {
			return false
		}
	}

	return true
}

// Time Complexity: O(K logN)
