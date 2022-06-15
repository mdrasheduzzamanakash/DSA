func isPerfectSquare(num int) bool {
	lo := 1
	hi := num

	for lo <= hi {
		mid := lo + (hi-lo)/2
		prod := mid * mid

		if prod < num {
			lo = mid + 1
		} else if prod > num {
			hi = mid - 1
		} else {
			return true
		}
	}

	return false
}
