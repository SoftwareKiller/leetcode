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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* curr = head;
        int len = 0;
        while(curr) {
            curr = curr->next;
            len++;
        }

        if (k >= len) {
            k %= len;
        }

        if (k == 0) {
            return head;
        }

        curr = head;
        ListNode* pre = head;
        while (curr->next) {
            curr = curr->next;
            if (k > 0) {
                k--;
            } else {
                pre = pre->next;
            }
        }
        curr->next = head;
        ListNode* ans = pre->next;
        pre->next = nullptr;
        return ans;
    }
};