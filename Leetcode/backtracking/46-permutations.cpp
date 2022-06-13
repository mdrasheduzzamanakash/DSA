class Solution {
    vector<vector<int>> acc;
    vector<int> nums;
    size_t n;

    void rec(int i) {
        if (i == n) {
            acc.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            rec(i + 1);
            swap(nums[i], nums[j]);
        }
    }

  public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        rec(0);
        return acc;
    }
};
