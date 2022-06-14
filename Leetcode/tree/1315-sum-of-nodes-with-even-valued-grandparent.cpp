// bfs, graph-traversal, tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int sumEvenGrandparent(TreeNode* root) {
        map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto v : {u->left, u->right}) {
                if (v) {
                    parent[v] = u;
                    q.push(v);
                    if (parent[u] and (parent[u]->val % 2 == 0))
                        sum += v->val;
                }
            }
        }

        return sum;
    }
};
