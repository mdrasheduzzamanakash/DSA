func countNegatives(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	count := 0
	for r, c := m-1, 0; r >= 0 && c < n; { // start from bottom-left position: grid[m-1][0]
		if grid[r][c] < 0 { // look in the previous row for first occurrence of a negative
			r--
			count += n - c
		} else { // look forward in the current row for first occurrence of a negative
			c++
		}
	}
	return count
}

// Time Complexity: O(m+n)
