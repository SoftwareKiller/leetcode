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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = head;
        while(fast && n > 0) {
            fast = fast->next;
            n--;
        }

        if (n > 0) {
            return head;
        }

        ListNode* pre = dummy;
        while(fast) {
            fast = fast->next;
            pre = pre->next;
        }
        if (pre->next) {
            pre->next = pre->next->next;
        }
        return dummy->next;
    }
};