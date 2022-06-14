#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 1e2;
vector<int> adj[MAXN];
bool visited[MAXN];

int main(void)
{
    int n;
    cin >> n;

    for (int u = 0; u < n; u++)
    {
        int v;
        while (cin >> v && v)
            adj[u].push_back(v - 1);
    }

    queue<int> q;
    vector<int> team(n);

    auto bfs = [&](int start) {
        int s = start;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (visited[v])
                    continue;
                visited[v] = true;
                q.push(v);
                team[v] = 1 ^ team[u];
            }
        }
    };

    for (int start = 0; start < n; start++)
        if (!visited[start])
            bfs(start);

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (team[i])
            ans.push_back(i + 1);

    cout << ans.size() << "\n";
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";
}
