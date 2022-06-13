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
    vector<string> paths;
    vector<int> path;
    
    void rec(TreeNode* root) {
        if (root->left == nullptr and root->right == nullptr) {
            stringstream ss;
            for (auto u: path) ss << u << "->";
            ss << root->val;
            paths.push_back(ss.str());
        }
        
        for (auto node: {root->left, root->right}) {
            if (not node) continue;
            path.push_back(root->val);
            binaryTreePaths(node);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        rec(root);
        return paths;
    }
};
