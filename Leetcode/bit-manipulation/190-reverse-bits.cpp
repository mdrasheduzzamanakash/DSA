class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r;
        int round = 32;
        while (round--) {
            uint8_t lsb = n & 1;
            n >>= 1;
            r <<= 1;
            r |= lsb;
        }
        return r;
    }
};
