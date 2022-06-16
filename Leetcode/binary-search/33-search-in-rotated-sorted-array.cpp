class Solution {
    int pit(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            if (hi - lo == 1) {
                if (nums[hi] > nums[lo])
                    return lo;
                else
                    return hi;
            }

            int mid = lo + (hi - lo) / 2;

            if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) // found the pit #//
                return mid;
            else if (nums[lo] > nums[mid] && nums[mid] < nums[hi]) // handles segments containinng
                hi = mid - 1;
            else if (nums[lo] < nums[mid] && nums[mid] > nums[hi]) // both side of the pit #//
                lo = mid + 1;
            else if (nums[mid] > nums[mid - 1]) // handles segments
                hi = mid - 1;
            else // that are sorted #//
                lo = mid + 1;
        }

        return lo;
    }

    int search(vector<int>& nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return -1;
    }

  public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        int p = pit(nums);
        int idx = search(nums, target, 0, p - 1);
        if (idx != -1)
            return idx;
        else
            return search(nums, target, p, nums.size() - 1);
    }
};
