#include <iostream>
using namespace std;

constexpr int MAXN = 56;
int a[MAXN];

int main(void) {
    int n;
    cin >> n;

    // base cases:
    // fixes 1 in its position.
    a[2] = a[1] = 1;
    a[3] = 2;

    for (int i = 4; i <= n; i++)
        a[i] = a[i - 1] + // 12..
               a[i - 3] + // 1324..
               1;         // 1....2  (odds followed by evens: 1357642)

    cout << a[n] << "\n";
}
