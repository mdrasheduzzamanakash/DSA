// Problem source: http://acm.timus.ru/problem.aspx?space=1&num=1494
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    bool cheating = false;
    int m = 0;
    stack<int> s;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        while (m < x)
            s.push(++m);
        if (s.top() != x)
            cheating = true;
        s.pop();
    }
    if (cheating)
        cout << "Cheater\n";
    else
        cout << "Not a proof\n";
}

/*
Test cases:
10
4 5 3 6 9 10 8 7 2 1
Not a proof
2 5 4 3 1
Not a proof
2 5 3 4 1
Cheater
*/
