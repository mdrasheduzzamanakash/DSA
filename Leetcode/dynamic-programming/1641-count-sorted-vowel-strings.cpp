class Solution {
    map<pair<int, int>, int> cache;

    int rec(int len, int ch) {
        if (len == 1)
            return 1;
        if (ch == 5) // "u" is followed by "u" only.
            return 1;
        if (cache.count({len, ch}))
            return cache[{len, ch}];

        return cache[{len, ch}] = rec(len - 1, ch) + rec(len, ch + 1);
    }

  public:
    int countVowelStrings(int n) {
        int a = rec(n, 1);
        int e = rec(n, 2);
        int i = rec(n, 3);
        int o = rec(n, 4);
        int u = rec(n, 5);
        return a + e + i + o + u;
    }
};

/*
encoding: a = 1, e = 2, i = 3, o = 4, u = 5

length = 1 (base case)
a: 1
e: 1
i: 1
o: 1
u: 1

length = 2
aX: 1 + 1 + 1 + 1 + 1
eX:     1 + 1 + 1 + 1
iX:         1 + 1 + 1
oX:             1 + 1
uX:                 1

length = 3
aXX: 5 + 4 + 3 + 2 + 1
eXX:     4 + 3 + 2 + 1
iXX:         3 + 2 + 1
oXX:             2 + 1
uXX:                 1

length = 4
aXXX: 15 + 10 + 6 + 3 + 1
eXXX:      10 + 6 + 3 + 1
iXXX:           6 + 3 + 1
oXXX:               3 + 1
uXXX:                   1

General Formula:
count[len][ch] = count[len-1][ch] + count[len][ch+1]
*/
