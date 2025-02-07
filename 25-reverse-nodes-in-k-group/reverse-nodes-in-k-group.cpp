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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = head;
        int n = 0;
        while(p) {
            p = p->next;
            n++;
        }

        p = dummy;
        ListNode* curr = p->next;
        ListNode* pre = nullptr;
        for (int i = n; i >= k; i-=k) {
            for (int j = 0; j < k; j++) {
                ListNode* nxt = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nxt;
            }
            ListNode* preGroup = p->next;
            p->next->next = curr;
            p->next = pre;
            p = preGroup;
        }
        return dummy->next;
    }
};