class Solution {
    int lowerBound(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target > arr[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        if (lo >= arr.size() or arr[lo] != target)
            return -1;
        return lo;
    }

    int upperBound(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target < arr[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        if (hi < 0 or arr[hi] != target)
            return -1;
        return hi;
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};

        vector<int> res;
        res.push_back(lowerBound(nums, target));
        res.push_back(upperBound(nums, target));
        return res;
    }
};
