class Solution {
  public:
    int numSplits(string s) {
        unordered_set<char> L, R;
        int n = s.size();
        vector<int> leftCount(n + 2), rightCount(n + 2);

        for (int i = 1; i <= n; i++) {
            leftCount[i] = leftCount[i - 1];
            if (L.count(s[i - 1]) == 0) {
                L.insert(s[i - 1]);
                leftCount[i]++;
            }
        }

        for (int i = n; i > 0; i--) {
            rightCount[i] = rightCount[i + 1];
            if (R.count(s[i - 1]) == 0) {
                R.insert(s[i - 1]);
                rightCount[i]++;
            }
        }

        if (leftCount[n] == 1) // there is only one unique character
            return n - 1;

        int splits = 0;
        for (int i = 1; i <= n; i++)
            if (leftCount[i] == rightCount[i + 1])
                splits++;
        return splits;
    }
};
