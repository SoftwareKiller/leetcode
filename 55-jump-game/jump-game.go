func canJump(nums []int) bool {
    forest := 0
    curr := 0
    end := len(nums) - 1

    for curr <= forest && curr < end {
        forest = max(forest, nums[curr]+curr)
        curr++
    }

    return forest >= end
}