// Author: irfanabduhu
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        int lo = 0;
        int hi = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
