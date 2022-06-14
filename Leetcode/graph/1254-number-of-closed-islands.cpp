class Solution {
    void visitIsland(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};
        while (!q.empty()) {
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + xs[i];
                int y = c + ys[i];

                if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 0)
                    continue;
                grid[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    void markOpenIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows{0, m - 1};
        for (int c = 0; c < n; c++) {
            for (int r : rows)
                if (grid[r][c] == 0) {
                    grid[r][c] = 1;
                    visitIsland(grid, r, c);
                }
        }

        vector<int> cols{0, n - 1};
        for (int r = 0; r < m; r++) {
            for (int c : cols)
                if (grid[r][c] == 0) {
                    grid[r][c] = 1;
                    visitIsland(grid, r, c);
                }
        }
    }

  public:
    int closedIsland(vector<vector<int>>& grid) {
        markOpenIsland(grid);

        int closedCounts = 0;
        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid[0].size() - 1; c++) {
                if (grid[r][c] == 0) {
                    closedCounts++;
                    grid[r][c] = 1;
                    visitIsland(grid, r, c);
                }
            }
        }

        return closedCounts;
    }
};
