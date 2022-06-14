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
    int goodNodes(TreeNode* root, int maxsofar = -10001) {
        if (root == nullptr)
            return 0;

        int isGood = root->val >= maxsofar;
        maxsofar = max(root->val, maxsofar);
        return isGood + goodNodes(root->left, maxsofar) + goodNodes(root->right, maxsofar);
    }
};
