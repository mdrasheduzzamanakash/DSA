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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        auto p = head;

        while (true) {
            p->next = nullptr;
            int i = -1;
            int index = 0; // index of the list with smallest head

            for (auto ls : lists) {
                i++;
                if (not ls)
                    continue;
                if ((not p->next) or (ls->val < p->next->val)) {
                    p->next = ls;
                    index = i;
                }
            }

            if (p->next == mx) {
                p->next = nullptr;
                break;
            }

            p = p->next;
            lists[index] = lists[index]->next;
        }

        return head->next;
    }
};
