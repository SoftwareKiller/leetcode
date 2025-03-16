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
        if (!head) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* curr = head;

        while(curr && curr->next) {
            if (curr->val != curr->next->val) {
                pre = curr;
                curr = curr->next;
                continue;
            }

            int val = curr->val;
            while(curr && val == curr->val) {
                curr = curr->next;
            }
            pre->next = curr;
        }

        return dummy->next;
    }
};