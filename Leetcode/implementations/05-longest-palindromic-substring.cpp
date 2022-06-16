class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (s == string(n, s[0]))
            return s;

        int from = 0;
        int longestSize = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            // repetition of s[i] --> s[i:j]
            int j = i;
            while (j < n and s[i] == s[j + 1])
                j++;

            // symmetry along s[i:j]
            int k = 1;
            while (i - k >= 0 and j + k < n and s[i - k] == s[j + k])
                k++;
            k--;

            int size = j - i + 1 + 2 * k;
            if (size > longestSize) {
                longestSize = size;
                from = i - k;
            }

            // longer solution is not possible from next positions:
            if (n - i < (longestSize / 2) - 1)
                break;
        }

        return s.substr(from, longestSize);
    }
};
