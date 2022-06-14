#include <cstdlib>
#include <iostream>
#include <numeric>
#include <utility>
using namespace std;

constexpr int MAXN = 1e5 + 1;
int parent[MAXN];
int ncomp; // number of component

int root(int u) {
    while (u != parent[u])
        u = parent[u] = parent[parent[u]]; // path compression
    return u;
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return;

    ncomp--;
    if (rand() % 2)
        parent[u] = v;
    else
        parent[v] = u;
}

pair<int, int> edges[MAXN];
int threads[MAXN]; // threads[i]; ith thread to be cut-off.
bool cuts[MAXN];   // cuts[i]: true means ith edge is supposed to be cut-off.
int ans[MAXN];     // ans[i]: number of components after ith cut-off.

int main(void) {
    int n, m;
    cin >> n >> m;
    ncomp = n;
    iota(parent, parent + n + 1, 0);

    for (int i = 1; i <= m; i++)
        cin >> edges[i].first >> edges[i].second;

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> threads[i];
        cuts[threads[i]] = true;
    }

    for (int i = 1; i <= m; i++) {
        if (cuts[i])
            continue;
        unite(edges[i].first, edges[i].second);
    }

    for (int i = q; i >= 1; i--) {
        ans[i] = ncomp;
        int u = edges[threads[i]].first;
        int v = edges[threads[i]].second;
        unite(u, v);
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << " ";
    cout << "\n";
}
