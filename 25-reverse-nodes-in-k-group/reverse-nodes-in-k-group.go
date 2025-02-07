/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    n := 0
    for curr := head; curr != nil; curr = curr.Next {
        n++
    }

    dummy := &ListNode{
        Next: head,
    }
    var pre *ListNode
    curr := head
    p := dummy
    for i := n; i >= k; i-=k {
        for j := 0; j < k; j++ {
            nxt := curr.Next
            curr.Next = pre
            pre = curr
            curr = nxt
        }
        preGroup := p.Next
        p.Next.Next = curr
        p.Next = pre
        p = preGroup
    }
    return dummy.Next
}