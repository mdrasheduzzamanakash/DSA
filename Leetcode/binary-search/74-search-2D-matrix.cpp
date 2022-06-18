class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m * n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / n;
            int c = mid % n;
            if (target < matrix[r][c])
                hi = mid - 1;
            else if (target > matrix[r][c])
                lo = mid + 1;
            else
                return true;
        }

        return false;
    }
};
