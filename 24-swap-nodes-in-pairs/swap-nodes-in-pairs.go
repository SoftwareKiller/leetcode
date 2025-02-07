/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    dummy := &ListNode{
        Next: head,
    }
    p := dummy
    for p.Next != nil && p.Next.Next != nil {
        l := p.Next
        r := p.Next.Next
        l.Next = r.Next
        r.Next = l
        p.Next = r
        p = p.Next.Next
    }

    return dummy.Next
}