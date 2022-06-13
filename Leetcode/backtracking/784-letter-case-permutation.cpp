class Solution {
    vector<string> acc;
    string s;
    size_t n;

    void changeCase(string& s, size_t index) {
        if (s[index] >= 'a' and s[index] <= 'z')
            s[index] -= 32;
        else if (s[index] >= 'A' and s[index] <= 'Z')
            s[index] += 32;
    }
    inline bool isNum(char c) { return c >= '0' and c <= '9'; }

    void rec(size_t index) {
        if (index == n) {
            acc.push_back(s);
            return;
        }

        if (isNum(s[index])) {
            rec(index + 1);
        } else {
            rec(index + 1);
            changeCase(s, index);
            rec(index + 1);
        }
    }

  public:
    vector<string> letterCasePermutation(string s) {
        this->s = s;
        this->n = s.size();
        rec(0);
        return acc;
    }
};
