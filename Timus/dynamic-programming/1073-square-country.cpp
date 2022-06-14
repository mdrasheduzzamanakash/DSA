#include <climits>
#include <iostream>
#include <vector>
#define INF (INT_MAX)
using namespace std;

constexpr int MAXN = 6e4 + 1;
int table[MAXN];

int main(void) {
    vector<int> squares(244);
    for (int i = 0; i < 244; i++)
        squares[i] = (i + 1) * (i + 1);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        table[i] = INF;
        for (auto s : squares) {
            if (i - s < 0)
                break;
            table[i] = min(table[i], 1 + table[i - s]);
        }
    }
    cout << table[n] << "\n";
}
