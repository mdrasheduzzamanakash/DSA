class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    grid[r][c] = -2;
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                    grid[r][c] = -1;
                }
            }
        }

        vector<int> dir{0, -1, 0, 1, 0};
        int maxTime = 0;
        while (!q.empty()) {
            auto [sr, sc] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = sr + dir[i];
                int y = sc + dir[i + 1];
                if (x < 0 or y < 0 or x >= m or y >= n or grid[x][y] == 0)
                    continue;
                if (grid[x][y] == -1) {
                    fresh--;
                    grid[x][y] = 1 + max(0, grid[sr][sc]);
                    maxTime = max(grid[x][y], maxTime);
                    q.push({x, y});
                }
            }
        }

        if (fresh)
            return -1;
        else
            return maxTime;
    }
};
