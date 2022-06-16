class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        lo = 0
        hi = m * n - 1

        while lo <= hi:
            mid = lo + (hi - lo) // 2
            r = mid // n
            c = mid % n
            if matrix[r][c] > target:
                hi = mid - 1
            elif matrix[r][c] < target:
                lo = mid + 1
            else:
                return True

        return False
