#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

constexpr int MAXN = 1e5;
pair<int, int> a[MAXN];

int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + N, [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

    int r = 1;
    int e = a[0].second;
    for (int i = 1; i < N; i++) {
        if (a[i].first <= e)
            continue;
        e = a[i].second;
        r++;
    }
    cout << r << "\n";
}
