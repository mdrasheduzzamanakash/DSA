class Solution {
    string s;
    string t;
    map<pair<int, int>, int> cache;

    int rec(int i, int j) {
        if (cache.count({i, j}))
            return cache[{i, j}];
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (s[i - 1] == t[j - 1])
            return rec(i - 1, j - 1);

        int a = 1 + rec(i - 1, j);
        int b = 1 + rec(i, j - 1);
        int c = 2 + rec(i - 1, j - 1);
        return cache[{i, j}] = min({a, b, c});
    }

  public:
    int minDistance(string word1, string word2) {
        s = word1;
        t = word2;
        return rec(s.size(), t.size());
    }
};
