// dfs, graph-traversal, dag
class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> paths;
    vector<int> path;
    int target;

    void dfs(int u) {
        if (u == target) {
            paths.push_back(path);
            return;
        }

        for (int v : adj[u]) {
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        adj = graph;
        target = graph.size() - 1;
        path.push_back(0);
        dfs(0);
        return paths;
    }
};
