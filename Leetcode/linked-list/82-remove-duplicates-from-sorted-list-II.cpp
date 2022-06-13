/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        while (head and head->next and head->val == head->next->val) {
            auto t = head;
            while (t->next and t->val == t->next->val) {
                t = t->next;
            }
            head = t->next;
        }

        if (head == nullptr or head->next == nullptr)
            return head;

        head->next = deleteDuplicates(head->next);
        return head;
    }
};
