func checkIfExist(arr []int) bool {
	sort.Ints(arr) // O(NlogN)

	for i, val := range arr { // N iterations
		var lo, hi int
		if val < 0 {
			lo, hi = 0, i-1
		} else {
			lo, hi = i+1, len(arr)-1
		}
		if binarySearch(arr, 2*val, lo, hi) { // O(logN)
			return true
		}
	}
	return false
}

func binarySearch(arr []int, target, lo, hi int) bool {
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if target < arr[mid] {
			hi = mid - 1
		} else if target > arr[mid] {
			lo = mid + 1
		} else {
			return true
		}
	}
	return false
}

// Time Complexity: O(NlogN)
// This problem can be solved in O(N) using HashSet
