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
    ListNode* partition(ListNode* head, int x) {
        ListNode* part1 = new ListNode();
        ListNode* part2 = new ListNode();
        ListNode* p1 = part1;
        ListNode* p2 = part2;

        while(head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }

            head = head->next;
        }

        p2->next = nullptr;
        p1->next = part2->next;
        return part1->next;
    }
};