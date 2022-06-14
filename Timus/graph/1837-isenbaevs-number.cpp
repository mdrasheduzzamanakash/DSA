#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define INF (INT_MAX / 2)
using namespace std;

constexpr int MAXP = 3e2; // maximum number of players
vector<int> adj[MAXP];
bool visited[MAXP];
int dist[MAXP];

int main(void) {
    int n;
    cin >> n;
    fill(dist, dist + MAXP, INF);
    map<string, int> id;

    // construction:
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        if (id.find(a) == id.end())
            id[a] = id.size();
        if (id.find(b) == id.end())
            id[b] = id.size();
        if (id.find(c) == id.end())
            id[c] = id.size();

        int u = id.find(a)->second;
        int v = id.find(b)->second;
        int w = id.find(c)->second;

        adj[u].push_back(v);
        adj[v].push_back(u);
        adj[v].push_back(w);
        adj[w].push_back(v);
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // BFS:
    int s;
    if (id.find("Isenbaev") != id.end()) {
        s = id.find("Isenbaev")->second;

        dist[s] = 0;
        visited[s] = true;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (visited[v])
                    continue;
                dist[v] = 1 + dist[u];
                visited[v] = true;
                q.push(v);
            }
        }

        for (auto p : id) {
            int d = dist[p.second];
            cout << p.first << " " << ((d == INF) ? "undefined" : to_string(d)) << "\n";
        }
    } else {
        for (auto p : id)
            cout << p.first << " "
                 << "undefined\n";
    }
}
