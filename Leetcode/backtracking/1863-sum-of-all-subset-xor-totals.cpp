class Solution {
    vector<int> nums;
    vector<int> vals;
    int n;
    int sum;
    void rec(int i) {
        if (i == n) {
            int x = 0;
            for (auto v : vals)
                x ^= v;
            sum += x;
            return;
        }
        vals.push_back(nums[i]);
        rec(i + 1);
        vals.pop_back();
        rec(i + 1);
    }

  public:
    int subsetXORSum(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        rec(0);
        return sum;
    }
};
