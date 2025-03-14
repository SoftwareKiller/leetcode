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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while(list1 || list2) {
            ListNode* curr = nullptr;
            if (list1 && list2) {
                if (list1->val < list2->val) {
                    curr = list1;
                    list1 = list1->next;
                } else {
                    curr = list2;
                    list2 = list2->next;
                }
            } else if (list1 == nullptr) {
                curr = list2;
                list2 = list2->next;
            } else {
                curr = list1;
                list1 = list1->next;
            }

            ptr->next = curr;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};