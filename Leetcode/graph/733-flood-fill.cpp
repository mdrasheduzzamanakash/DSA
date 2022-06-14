class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> res(m);
        for (auto i = 0; i < m; i++)
            res[i] = image[i];

        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return res;

        vector<int> xs{-1, 1, 0, 0};
        vector<int> ys{0, 0, -1, 1};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto x = u.first;
            auto y = u.second;
            res[x][y] = newColor;

            for (int i = 0; i < 4; i++) {
                auto r = x + xs[i];
                auto c = y + ys[i];
                if (r < 0 || c < 0 || r >= m || c >= n || res[r][c] != oldColor)
                    continue;
                q.push({r, c});
            }
        }

        return res;
    }
};
