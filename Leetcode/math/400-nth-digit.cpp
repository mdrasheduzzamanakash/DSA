class Solution {
  public:
    int findNthDigit(int n) {
        // 9, 90*2, 900*3, 9000*4, 90000*5
        int ndigit = 1;
        int base = 1;
        while (true) {
            int capacity = 9 * ndigit * base;
            if (n <= capacity)
                break;
            n -= capacity;
            ndigit++;
            base *= 10;
            if (base > INT_MAX / 9 / ndigit)
                break;
        }

        base--;
        base += (n + ndigit - 1) / ndigit; // added (ndigit-1) to perform ceiling
        int idx = n % ndigit;
        idx = idx != 0 ? idx : ndigit;
        int shift = ndigit - idx;
        // cout << base << " idx: " << idx << " shift: " << shift << endl;
        while (shift--)
            base /= 10;
        return base % 10;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
// Example: n = 15                                                                     //
// 12345678910111213                                                                   //
//               ^---- this is the anwer                                               //
//                                                                                     //
// With 1 digit we can reach up to 9; n = n - capacity = (15 - 9) = 6.                 //
// Increase the number of digit to 2.                                                  //
// Now, base = 10, guess = base - 1;  because we only made move for ndigit-1 so far.   //
// Here, making move means reducing n by the capacity of a particular digits coverage. //
//                                                                                     //
// For each increment of guess we can move forward two indices (= number of digits)    //
// Make the jump at once: guess = guess + n / ndigit = 9 + 6/2 = 12                    //
// Desired position: pos = n % ndigit = 12 % 2 = 0 -> 2                                //
// guess[1] = 1                                                                        //
// guess[2] = 2                                                                        //
// So, answer = 2                                                                      //
/////////////////////////////////////////////////////////////////////////////////////////
