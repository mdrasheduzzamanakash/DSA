#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <cstring>
using namespace std;

const int mx = 100005;
int cnt;
int* parents, *sizes;
void init(int n) {
    parents = new int[n + 5];
    sizes = new int[n + 5];

    for(int i = 0; i <= n; ++i) parents[i] = i, sizes[i] = 1;
    cnt = n;
}

int find(int x) {
    while(x != parents[x]) x = parents[x];
    return x;
}

bool isConnected(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if(a < b) swap(a, b);
    parents[b] = a;
    sizes[a] += sizes[b];
    cnt--;
}

int count() {
    return cnt;
}

int main() {
    int n, m, q, t1, t2;
    cin >> n >> m;
    init(n);
    pair< int, int > threads[m + 1];
    for(int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        threads[i] = {t1, t2};
    }
    cin >> q;
    int qcopy = q;
    int not_safe_threads[m + 5];
    bool *not_safe = new bool[m + 5];
    memset(not_safe, false, (m + 5) * sizeof(bool));

    while(q--) {
        cin >> t1;
        not_safe[t1 - 1] = true;
        not_safe_threads[q] = t1 - 1;
    }
    q = qcopy;
    for(int i = 0; i < m; i++) {
        if(not_safe[i]) continue;
        unite(threads[i].first, threads[i].second);
    }
    delete[] not_safe;
    stack< int > ans;
    for(int i = 0; i < q; i++) {
        ans.push(count());
        pair<int, int> not_safe_thread = threads[not_safe_threads[i]];
        unite(not_safe_thread.first, not_safe_thread.second);
    }

    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout <<  endl;

    return 0;
}
