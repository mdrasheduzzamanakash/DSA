class Solution {
  public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> table(n + 1);
        for (int i = 0; i < n + 1; i++)
            table[i].resize(m + 1);

        int length = 0;
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++)
                if (nums1[i - 1] == nums2[j - 1]) {
                    table[i][j] = 1 + table[i - 1][j - 1];
                    length = max(length, table[i][j]);
                }

        return length;
    }
};

// Time Complexity: O(MN)
// Space Complexity: O(MN)
