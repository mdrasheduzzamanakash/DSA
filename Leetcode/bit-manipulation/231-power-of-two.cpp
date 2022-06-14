class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        if (n & 1)
            return n == 1;
        return isPowerOfTwo(n / 2);
    }
};
