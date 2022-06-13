class Solution {
    vector<vector<int>> combinations;
    vector<int> v;

    void rec(int x, int k) {
        if (k == 0) {
            combinations.push_back(v);
            return;
        }
        if (x < 1)
            return;

        v.push_back(x);
        rec(x - 1, k - 1);
        v.pop_back();
        rec(x - 1, k);
    }

  public:
    vector<vector<int>> combine(int n, int k) {
        rec(n, k);
        return combinations;
    }
};
