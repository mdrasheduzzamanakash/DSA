class Solution {
  public:
    bool checkOnesSegment(string s) {
        bool hasZero = false;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                hasZero = true;
            else if (hasZero)
                return false;

        return true;
    }
};
