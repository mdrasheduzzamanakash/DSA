class Solution {
  public:
    int hammingWeight(uint32_t n) {
        if (n == 0)
            return 0;
        if (n & 1)
            return 1 + hammingWeight(n >> 1);
        return hammingWeight(n >> 1);
    }

    int hammingWeightIterative(uint32_t n) {
        int res = 0;
        while (n) {
            if (n & 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};
