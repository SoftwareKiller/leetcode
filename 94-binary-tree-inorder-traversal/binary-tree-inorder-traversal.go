/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    ans := make([]int, 0)

    var inorder func(*TreeNode)
    inorder = func(subRoot *TreeNode) {
        if subRoot == nil {
            return
        }

        inorder(subRoot.Left)
        ans = append(ans, subRoot.Val)
        inorder(subRoot.Right)
    }
    inorder(root)
    return ans
}
