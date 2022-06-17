class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid == 0 or mid == hi)
                return nums[lo] > nums[hi] ? lo : hi;

            if (nums[mid - 1] > nums[mid])
                hi = mid - 1;
            else if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else
                return mid;
        }

        return lo;
    }
};
