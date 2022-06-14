#include <cmath>
#include <iostream>
using namespace std;

constexpr int MAXN = 2.5e4;
int table[MAXN][14];

int main(void) {
    int m;
    cin >> m;
    int n = 0; // size of the container

    int tmp;
    while (cin >> tmp && tmp != -1) // input + initialization
        table[n++][0] = tmp;

    int p = log2(n);
    for (int j = 1; j <= p; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

    p = log2(m);
    for (int i = 0; i <= n - m; i++)
        cout << max(table[i][p], table[i + m - (1 << p)][p]) << "\n";
}
