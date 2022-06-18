class Solution {
  public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid == lo or mid == hi)
                return min(nums[lo], nums[hi]);
            if (nums[mid - 1] > nums[mid] and nums[mid] < nums[mid + 1])
                return nums[mid];

            if (nums[lo] > nums[mid]) // pit is in the left half.
                hi = mid - 1;
            else if (nums[mid] > nums[hi]) // pit is in the right half.
                lo = mid + 1;
            else // properly sorted in ascending order; lowest comes first.
                hi = mid - 1;
        }

        return nums[lo];
    }
};
