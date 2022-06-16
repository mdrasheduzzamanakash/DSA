class Solution {
  public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, vector<int>> beginsWith;
        for (int i = 0; i < m; i++)
            beginsWith[nums2[i]].push_back(i);

        int length = 0;
        for (int i = 0; i < n - length; i++) {
            for (int j : beginsWith[nums1[i]]) {
                if (m - j <= length)
                    continue;
                for (int k = 0; i + k < n and j + k < m and nums1[i + k] == nums2[j + k]; k++)
                    length = max(k + 1, length);
            }
        }

        return length;
    }
};

// Insight: most of the time nums1[i] != nums2[j]
// Only explore for those j where nums1[i] == nums2[j]
