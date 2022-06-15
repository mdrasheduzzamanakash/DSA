# author: shiponcs
# https://leetcode.com/problems/island-perimeter/

class Solution:
    cnt = 0        
    def inc():
        Solution.cnt = Solution.cnt + 1
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        Solution.cnt = 0
        row = len(grid)
        col = len(grid[0])
        
        for i in range( row ):
            for j in range( col ):
                print(i, j)
                if grid[i][j] == 0:           
                    continue
                if  i - 1 == -1:
                    Solution.inc()
                elif grid[i - 1][j] == 0:
                    Solution.inc() 
                if i + 1 == row:
                    Solution.inc()
                elif grid[i + 1][j] == 0:
                    Solution.inc()
                if  j - 1 == -1:
                    Solution.inc()
                elif grid[i][j - 1] == 0:
                    Solution.inc() 
                if j + 1 == col:
                    Solution.inc()
                elif grid[i][j + 1] == 0:
                    Solution.inc()
                
        return Solution.cnt
