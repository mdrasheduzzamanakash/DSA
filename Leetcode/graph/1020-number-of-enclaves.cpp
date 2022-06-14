class Solution {
    void visitNeighbors(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        grid[sr][sc] = 0;
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
                grid[x][y] = 0;
                q.push({x, y});
            }
        }
    }

    void markOffCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int c = 0; c < n; c++) {
            if (grid[0][c])
                visitNeighbors(grid, 0, c);
            if (grid[m - 1][c])
                visitNeighbors(grid, m - 1, c);
        }

        for (int r = 1; r < m - 1; r++) {
            if (grid[r][0])
                visitNeighbors(grid, r, 0);
            if (grid[r][n - 1])
                visitNeighbors(grid, r, n - 1);
        }
    }

  public:
    int numEnclaves(vector<vector<int>>& grid) {
        markOffCells(grid);

        int enclaves = 0;
        for (auto row : grid)
            for (auto x : row)
                enclaves += x;

        return enclaves;
    }
};
