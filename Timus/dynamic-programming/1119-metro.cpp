#include <cmath>
#include <iostream>
using namespace std;

constexpr int MAXN = 1e3 + 1;
double grid[MAXN][MAXN];

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    double r = sqrt(2e4);

    while (k--) {
        int i, j;
        cin >> i >> j;
        grid[i][j] = -1;
    }

    // base cases:
    for (int i = 1; i <= n; i++)
        grid[i][0] = i * 100;
    for (int j = 1; j <= m; j++)
        grid[0][j] = j * 100;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (grid[i][j] == -1)
                grid[i][j] = r + grid[i - 1][j - 1];
            else
                grid[i][j] = 100 + min(grid[i - 1][j], grid[i][j - 1]);

    cout << round(grid[n][m]) << "\n";
}
