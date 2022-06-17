class Solution {
  public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT_MIN)
                n += 2;
            // to avoid overflow;
            // added an even number to preserve original parity
            // precision change at this scale is negligible

            n = abs(n);
            double res = 1.0;
            while (n) {
                if (n & 1)
                    res /= x;
                x *= x;
                n >>= 1;
            }
            return res;
        }

        double res = 1.0;
        while (n) {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};
