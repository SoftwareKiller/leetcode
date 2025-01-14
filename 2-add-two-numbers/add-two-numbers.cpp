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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0, nullptr);
        ListNode* curr = &dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry > 0) {
            int v = 0;
            if (l1 != nullptr) {
                v += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                v += l2->val;
                l2 = l2->next;
            }

            if (carry > 0) {
                v += carry;
                carry = 0;
            }

            if (v >= 10) {
                carry = v / 10;
                v %= 10;
            }

            ListNode* node = new ListNode(v, nullptr);
            curr->next = node;
            curr = curr->next;
        }
        return dummy.next;
    }
};