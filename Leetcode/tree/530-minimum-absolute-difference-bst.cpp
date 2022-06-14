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
    vector<int> vals;

    /*
    ** Inorder traversal to get all values in ascending order.
    ** Time Complexity: O(N)
    ** Space Complexity: O(N)
    ** N: #nodes
    */
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return;

        traverse(root->left);
        vals.push_back(root->val);
        traverse(root->right);
    }

  public:
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        int d = vals[1] - vals[0];
        for (int i = 2; i < vals.size(); i++)
            d = min(d, vals[i] - vals[i - 1]);
        return d;
    }
};
