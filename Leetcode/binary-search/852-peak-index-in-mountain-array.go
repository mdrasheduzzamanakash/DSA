func peakIndexInMountainArray(arr []int) int {
	lo := 1
	hi := len(arr) - 2

	for lo <= hi {
		mid := lo + (hi-lo)/2

		if arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] {
			return mid
		} else if arr[mid-1] < arr[mid] {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	return -1 // there is no peak
}
