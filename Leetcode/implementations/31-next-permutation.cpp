// Hints from https://www.tutorialcup.com/interview/string/next-permutation.htm
class Solution {
    // Find the index of an element that is just above the target,
    // where the array is sorted in descending order.
    int upperBound(vector<int> arr, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target < arr[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }

  public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;

        int n = nums.size();
        int i = n - 1;
        while (i > 0 and nums[i - 1] >= nums[i])
            i--;
        i--;
        // Now, nums[i+1:] is sorted in descending order

        if (i < 0) {
            // All elements are in descending order.
            // No more lexicographically larger permutation exists.
            // Hence, reverse it to reset the arrangement.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the index of an element that is just above nums[i]
        int j = upperBound(nums, i + 1, n - 1, nums[i]);
        swap(nums[i], nums[j]);
        // Now, nums[i] has been set correctly for the next permutation

        // nums[i+1:] is still in descending order.
        // Reverse it to reset the arrangement in this part.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
