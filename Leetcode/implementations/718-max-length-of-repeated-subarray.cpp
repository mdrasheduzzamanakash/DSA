class Solution {
  public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int length = 0;

        for (int i = 0; i < n - length; i++)
            for (int j = 0; j < n - length; j++)
                for (int k = 0; i + k < n and j + k < n and nums1[i + k] == nums2[j + k]; k++)
                    length = max(k + 1, length);

        return length;
    }
};
