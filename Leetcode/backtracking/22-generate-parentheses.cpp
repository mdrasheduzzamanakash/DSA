// backtracking
class Solution {
    vector<string> parentheses;
    string paren;
    int n;

    void rec(int open, int close) {
        if (open == n and close == n) {
            parentheses.push_back(paren);
            return;
        }

        int index = open + close;

        if (open < n) {
            paren[index] = '(';
            rec(open + 1, close);
        }

        if (close < open) {
            paren[index] = ')';
            rec(open, close + 1);
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        paren.resize(2 * n);
        rec(0, 0);
        return parentheses;
    }
};
