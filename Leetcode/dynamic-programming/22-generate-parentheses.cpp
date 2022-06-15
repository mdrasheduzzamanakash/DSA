// dynamic-programming
// Idea from LC/wz2326
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> parens(n + 1);
        parens[0].push_back("");

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                for (auto p : parens[j]) {
                    string left = "(" + p + ")";
                    for (auto right : parens[i - j - 1])
                        parens[i].push_back(left + right);
                }
            }
        }

        return parens[n];
    }
};

// f(n) = ( f(x) ) f(n-x-1)
// We know, 1 + x + (n-x-1) = n
