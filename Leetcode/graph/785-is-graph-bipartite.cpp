class Solution {
    enum Colors { EMPTY = -1, WHITE, BLACK };

  public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, EMPTY); // -1: not colored yet

        queue<int> q;
        bool isbipartite = true;

        auto bfs = [&](int source) {
            q.push(source);
            color[source] = WHITE;

            while (!q.empty() and isbipartite) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[u] == color[v]) {
                        // v is already visited; and has the same color as its neighbour u.
                        isbipartite = false;
                        break;
                    }
                    if (color[v] != -1)
                        continue; // already visited; and has a different color

                    color[v] = BLACK ^ color[u];
                    q.push(v);
                }
            }
        };

        // The graph may not be connected:
        for (int u = 0; u < n; u++)
            if (color[u] == -1)
                bfs(u);

        return isbipartite;
    }
};
