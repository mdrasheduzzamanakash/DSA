class Solution {
  public:
    bool checkZeroOnes(string s) {
        s.push_back('#'); // sentinel
        int zeroRun = 0;
        int oneRun = 0;

        int run = 0;
        char prev = '$';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == prev) {
                run++;
                continue;
            }
            if (prev == '0')
                zeroRun = max(zeroRun, run);
            else
                oneRun = max(oneRun, run);
            run = 1;
            prev = s[i];
        }

        return oneRun > zeroRun;
    }
};
