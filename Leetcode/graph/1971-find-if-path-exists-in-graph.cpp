// graph-traversal, bfs
class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;

        // construct the bi-directional graph:
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // bfs:
        queue<int> q;
        q.push(source);
        vector<bool> visited(n);
        visited[source] = true;

        while (!q.empty()) {
            // explore a node:
            int u = q.front();
            q.pop();

            // visit its neighbors:
            for (auto v : adj[u]) {
                if (v == destination)
                    return true;
                if (visited[v])
                    continue;
                visited[v] = true;
                q.push(v);
            }
        }

        // destination not found:
        return false;
    }
};
