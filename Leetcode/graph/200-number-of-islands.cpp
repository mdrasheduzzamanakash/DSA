class Solution {
    void visit(vector<vector<char>>& grid, int sr, int sc) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        grid[sr][sc] = 'v';

        int m = grid.size();
        int n = grid[0].size();
        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};
        int r, c;

        while (!q.empty()) {
            tie(r, c) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = r + xs[i];
                int y = c + ys[i];
                if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1')
                    continue;
                grid[x][y] = 'v';
                q.push({x, y});
            }
        }
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    visit(grid, r, c);
                }
            }
        }

        return islands;
    }
};
