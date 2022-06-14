#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    stack<char> st;
    st.push('.'); // sentinels

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == st.top())
            st.pop();
        else
            st.push(s[i]);
    }

    int n = st.size() - 1;
    vector<char> r(n);
    for (int i = 0; i < n; i++)
        r[i] = st.top(), st.pop();

    for (auto it = r.rbegin(); it != r.rend(); it++)
        cout << *it;
    cout << "\n";
}
