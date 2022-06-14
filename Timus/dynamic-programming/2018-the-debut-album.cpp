#include <iostream>
using namespace std;

constexpr int MAXN = 5e4 + 1;
constexpr int MOD = 1e9 + 7;
int table[MAXN][2];
// table[i][0]: with an i-song album, in how many ways can the last song be 1?
// table[i][1]: with an i-song album, in how many ways can the last song be 2?

inline int sum(int a, int b) { return (a + b) % MOD; }

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    table[0][0] = table[0][1] = 1; // sentinels
    // Think about it in this way: we can be at position 0, and have the option
    // to choose 0 or 1 for the next positions.
    // If there were no such way to be at position 0 and make those decisions,
    // we would say T[0][0] = T[0][1] = 0.

    for (int i = 0; i < n; i++) // done up to this position.
    {
        // We can be at position i, where the ith element is 2, in T[i][1] many ways.
        // Each of the next A position(s) can be 1 in a valid permutation.

        // Say, there are X ways to be at position P, where P is 2, and it is valid
        // to have upto A many 1's contiguously.
        // If we choose 1 for a particular position Q, we have X many valid permutation
        // with these setup: the Pth position is 2, and the Qth position is 1.
        // This statement holds for each of the next A positions from P.

        // The same kind of rational applies when the Pth position holds 1 instead of 2.

        for (int j = 1; j <= a && i + j <= n; j++)
            table[i + j][0] = sum(table[i + j][0], table[i][1]);

        for (int j = 1; j <= b && i + j <= n; j++)
            table[i + j][1] = sum(table[i + j][1], table[i][0]);
    }

    cout << sum(table[n][0], table[n][1]) << "\n";
}
