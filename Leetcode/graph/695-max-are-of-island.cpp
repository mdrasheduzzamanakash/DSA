class Solution {
    int visit(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        grid[sr][sc] = -1; // visited
        int area = 1;

        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};
        int r, c;

        while (!q.empty()) {
            tie(r, c) = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + xs[i];
                int y = c + ys[i];
                if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1)
                    continue;
                grid[x][y] = -1;
                area++;
                q.push({x, y});
            }
        }

        return area;
    }

  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(visit(grid, r, c), maxArea);
                }
            }
        }

        return maxArea;
    }
};
