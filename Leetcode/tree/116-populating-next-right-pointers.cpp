/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        queue<Node*> q;
        q.push(root);

        int prevCount = 1;
        while (!q.empty()) {
            int currentCount = 0;
            while (prevCount--) {
                auto node = q.front();
                q.pop();

                if (prevCount)
                    node->next = q.front();
                else
                    node->next = nullptr;

                if (node->left) {
                    q.push(node->left);
                    currentCount++;
                }
                if (node->right) {
                    q.push(node->right);
                    currentCount++;
                }
            }
            prevCount = currentCount;
        }

        return root;
    }
};
