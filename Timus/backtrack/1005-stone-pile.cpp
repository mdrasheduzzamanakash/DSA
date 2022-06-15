#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int first, second;
vector<int> weights;

int diff(int i) {
    if (i == n)
        return abs(first - second);

    int d = abs(first - second);
    for (int j = i; j < n; j++) {
        first -= weights[j];
        second += weights[j];
        d = min(d, diff(j + 1));
        first += weights[j];
        second -= weights[j];
    }
    return d;
}

int main(void) {
    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        first += weights[i];
    }

    cout << diff(0) << endl;
}
