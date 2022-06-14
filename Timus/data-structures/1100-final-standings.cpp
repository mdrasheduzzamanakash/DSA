#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

constexpr int MAXN = 1.5e5;
tuple<int, int, int> teams[MAXN]; // (index, id, number of problem solved)

int main(void) {
    int n;
    cin >> n;
    for (int i = 0, id, m; i < n; i++) {
        cin >> id >> m;
        teams[i] = {i, id, m};
    }

    sort(teams, teams + n, [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return (get<2>(a) == get<2>(b)) ? get<0>(a) < get<0>(b) : get<2>(a) > get<2>(b);
    });

    for (int i = 0; i < n; i++) {
        auto t = teams[i];
        cout << get<1>(t) << " " << get<2>(t) << "\n";
    }
}
