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
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;
        while(p->next && p->next->next) {
            ListNode* l = p->next;
            ListNode* r = p->next->next;
            l->next = r->next;
            r->next = l;
            p->next = r;
            p = p->next->next;
        }
        return dummy->next;
    }
};