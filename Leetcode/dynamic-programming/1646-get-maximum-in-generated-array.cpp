class Solution {
  public:
    int getMaximumGenerated(int n) {
        if (n <= 1)
            return n;

        vector<int> nums(n + 1);
        nums[1] = 1;
        int mx = 1;
        for (int i = 2; i <= n; i++) {
            nums[i] = nums[i / 2];
            if (i & 1)
                nums[i] += nums[i / 2 + 1];
            mx = max(mx, nums[i]);
        }

        return mx;
    }
};
