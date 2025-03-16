/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return head
    }

    dummy := &ListNode{}
    dummy.Next = head
    pre := dummy
    curr := head

    for curr != nil && curr.Next != nil {
        if curr.Val != curr.Next.Val {
            pre = curr;
            curr = curr.Next
            continue
        }

        val := curr.Val
        for curr != nil && val == curr.Val {
            curr = curr.Next
        }
        pre.Next = curr
    }

    return dummy.Next
}