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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        // take care of head
        auto p = head->next;
        head->next = p->next;
        p->next = head;
        head = p;

        // subsequent pairs of nodes:
        p = head->next;
        while (p->next and p->next->next) {
            auto q = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }

        return head;
    }
};
