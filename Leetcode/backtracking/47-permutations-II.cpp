class Solution {
    vector<vector<int>> acc;
    vector<int> vals;
    int n;

    void rec(int pos) {
        if (pos == n) {
            acc.push_back(vals);
            return;
        }

        for (int j = pos; j < n; j++) {
            if (j != pos and vals[j] == vals[pos])
                continue;
            swap(vals[pos], vals[j]);
            rec(pos + 1);
        }

        // reset to previous state:
        for (int j = n - 1; j > pos; j--)
            swap(vals[pos], vals[j]);
    }

  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vals = nums;
        n = nums.size();
        rec(0);
        return acc;
    }
};
