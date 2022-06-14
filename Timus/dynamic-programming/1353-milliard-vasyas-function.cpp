#include <algorithm>
#include <iostream>
using namespace std;

int table[10][82];
// table[p][x]: in how many ways SOD can be x, up to pth position (rtl)?

int main(void) {
    // base cases:
    for (int s = 0; s <= 9; s++)
        table[1][s] = 1;

    for (int p = 2; p <= 9; p++)
        for (int s = 0; s <= 81; s++)
            for (int d = 0; d <= 9 && s - d >= 0; d++) // current digit
                table[p][s] += table[p - 1][s - d];

    int s;
    cin >> s;
    cout << table[9][s] + (s == 1) << "\n";
}
