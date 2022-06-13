class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev = triangle[n - 1];

        for (int r = n - 2; r >= 0; r--) {
            vector<int> current;
            for (int c = 0; c < triangle[r].size(); c++) {
                int elem = triangle[r][c] + min(prev[c], prev[c + 1]);
                current.push_back(elem);
            }
            prev = current;
        }

        return prev[0];
    }
};
