func mySqrt(x int) int {
	lo := 0
	hi := x

	for lo <= hi {
		mid := lo + (hi-lo)/2
		prod := mid * mid
		if prod < x {
			lo = mid + 1
		} else if prod > x {
			hi = mid - 1
		} else {
			return mid
		}
	}

	return hi
}
