func arrangeCoins(n int) int {
	mask := 1 << 15
	rows := 0 // number of rows that can be completely filled

	for mask > 0 {
		rows |= mask // set the bit

		var blocks int // total number of blocks in rows
		if rows&1 == 1 {
			blocks = ((rows + 1) / 2) * rows
		} else {
			blocks = (rows / 2) * (rows + 1)
		}

		if blocks > n {
			rows ^= mask // unset the bit
		}

		mask >>= 1
	}

	return rows
}

// 7 * 8 / 2 = 4 * 7 = (8 / 2) * 7
// when x is odd: sum(x) = ((x+1) / 2) * x

// 8 * 9 / 2 = 4 * 9 = (8 / 2) * 9
// when x is even: sum(x) = (x / 2) * (x+1)
