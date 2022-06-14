// Observation: The last stripe of any window must be red or white.
#include <iostream>
using namespace std;

using ll = long long;
constexpr int MAXN = 46;
enum Color { R, W };

ll window[MAXN][2];
// window[i][R]: how many decoration of i-stripe ends with red.
// window[i][W]: how many decoration of i-stripe ends with white.
ll solve(int n) {
    // base cases
    window[1][W] = window[1][R] = 1;
    window[2][W] = window[2][R] = 1;

    // Observation: if the last stripe is red, then the penultimate stripe
    // xor the third last stripe must be white, and vice versa.
    for (int f = 3; f <= n; f++) {
        window[f][R] = window[f - 1][W] + window[f - 2][W];
        window[f][W] = window[f - 1][R] + window[f - 2][R];
    }
    return window[n][R] + window[n][W];
}

ll flag[MAXN];
// flag[i]: how many decoration of i-stripe ends with red/white.
ll solve2(int n) {
    flag[1] = 2;
    flag[2] = 2;

    for (int f = 3; f <= n; f++)
        flag[f] = flag[f - 1] + flag[f - 2];

    return flag[n];
}

int main(void) {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    cout << solve2(n) << "\n";
}
