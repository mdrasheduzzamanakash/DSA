// bfs
// To avoid TLE, took suggestions from LC/hiepit
class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0)
                    q.push({r, c});
                else
                    mat[r][c] = -1; // mark as unprocessed
            }
        }

        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};

        while (!q.empty()) {
            auto [sr, sc] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = sr + xs[i];
                int y = sc + ys[i];
                if (x < 0 or y < 0 or x >= m or y >= n)
                    continue;
                if (mat[x][y] == -1) {
                    mat[x][y] = 1 + mat[sr][sc];
                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};
