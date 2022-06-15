func Abs(n int) int {
	if n < 0 {
		return -n
	} else {
		return n
	}
}

func isDistant(num, d int, arr []int) (ans bool) {
	n := len(arr)
	lo := 0
	hi := n - 1

	for lo <= hi {
		mid := lo + (hi-lo)/2
		if num < arr[mid] {
			hi = mid - 1
		} else if num > arr[mid] {
			lo = mid + 1
		} else {
			ans = false
			return
		}
	}

	if lo == n {
		return Abs(arr[lo-1]-num) > d
	} else if lo == 0 {
		return Abs(arr[lo]-num) > d
	} else {
		ans = (Abs(arr[lo]-num) > d) && (Abs(arr[lo-1]-num) > d)
		if lo+1 < n {
			ans = ans && Abs(arr[lo+1]-num) > d
		}
		return
	}
}

func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	sort.Ints(arr2[:])

	distance := 0

	for _, val := range arr1 {
		if isDistant(val, d, arr2) {
			distance++
		}
	}

	return distance
}
