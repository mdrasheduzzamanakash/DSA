#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

constexpr int MAXN = 2.5e5;
int a[MAXN / 2 + 2];

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n / 2 + 1; i++)
        cin >> a[i];
    make_heap(a, a + n / 2 + 1);

    for (int i = n / 2 + 1; i < n; i++) {
        cin >> a[n / 2 + 1];
        push_heap(a, a + n / 2 + 2);
        pop_heap(a, a + n / 2 + 2);
    }

    double median;
    if (n % 2 != 0)
        median = a[0];
    else {
        median = (1. * a[0]) / 2;
        pop_heap(a, a + n / 2 + 1);
        median += (1. * a[0]) / 2;
    }

    cout << setprecision(1) << fixed << median << "\n";
}
