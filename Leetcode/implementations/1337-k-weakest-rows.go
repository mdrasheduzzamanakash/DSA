import "sort"

func kWeakestRows(mat [][]int, k int) []int {
	m := len(mat)
	rows := make([][2]int, m)
	for i, row := range mat {
		count := countOnes(row)
		rows[i] = [2]int{count, i}
	}

	sort.Slice(rows, func(i, j int) bool {
		if rows[i][0] < rows[j][0] {
			return true
		} else if rows[i][0] > rows[j][0] {
			return false
		}
		return rows[i][1] < rows[j][1]
	})

	var res []int
	for i := 0; i < k; i++ {
		res = append(res, rows[i][1])
	}
	return res
}

func countOnes(row []int) int {
	count := 0
	for _, val := range row {
		count += val
	}
	return count
}
