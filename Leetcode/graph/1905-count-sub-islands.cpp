class Solution {
    void markDeadCells(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (grid2[r][c] and (not grid1[r][c]))
                    grid2[r][c] = -1; // mark dead
    }

    bool isSubisland(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();
        bool condition = true;

        queue<pair<int, int>> q;
        grid[sr][sc] = 0; // marked visited
        q.push({sr, sc});

        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};
        int r, c;

        while (!q.empty()) {
            tie(r, c) = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + xs[i];
                int y = c + ys[i];
                if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
                    continue;
                if (grid[x][y] == -1) {
                    condition = false;
                    continue;
                }
                grid[x][y] = 0;
                q.push({x, y});
            }
        }

        return condition;
    }

    int countSubisland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (grid[r][c] == 1)
                    count += isSubisland(grid, r, c);

        return count;
    }

  public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        markDeadCells(grid1, grid2);
        return countSubisland(grid2);
    }
};
