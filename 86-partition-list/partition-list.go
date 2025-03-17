/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    partOne := &ListNode{}
    partTwo := &ListNode{}

    pOne := partOne
    pTwo := partTwo

    for head != nil {
        if head.Val < x {
            pOne.Next = head
            pOne = pOne.Next
        } else {
            pTwo.Next = head
            pTwo = pTwo.Next
        }

        head = head.Next
    }

    pTwo.Next = nil
    pOne.Next = partTwo.Next

    return partOne.Next
}