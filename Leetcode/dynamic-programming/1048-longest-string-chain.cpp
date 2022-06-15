class Solution {
    bool isPredecessor(const string& a, const string& b) {
        if (b.size() - a.size() != 1)
            return false;

        for (int i = 0, j = 0; i < a.size(); j++) {
            if (j == b.size())
                return false;
            if (a[i] == b[j])
                i++;
        }

        return true;
    }

  public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) { return a.size() < b.size(); });

        int n = words.size();

        // chainLength[i]: max length of a chain that ends with ith word.
        vector<int> chainLength(n, 1);
        chainLength[0] = 1;
        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (chainLength[j] >= chainLength[i] and isPredecessor(words[j], words[i])) {
                    chainLength[i] = 1 + chainLength[j];
                    maxLength = max(chainLength[i], maxLength);
                }
            }
        }

        return maxLength;
    }
};
