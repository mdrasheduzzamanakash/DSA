/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

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
class FindElements {
    TreeNode* tree;
    unordered_set<int> vals;

    void rec(TreeNode* root) {
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            vals.insert(root->left->val);
            rec(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            vals.insert(root->right->val);
            rec(root->right);
        }
    }

  public:
    FindElements(TreeNode* root) {
        root->val = 0;
        vals.insert(root->val);
        rec(root);
        tree = root;
    }

    bool find(int target) { return vals.find(target) != vals.end(); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
