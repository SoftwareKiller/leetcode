func removeDuplicates(nums []int) int {
    count := 0
    current := 1

    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[i-1] {
            count = 0
            nums[current] = nums[i]
            current++
        } else {
            count++
            if count <= 1 {
                nums[current] = nums[i]
                current++
            }
        }
    }

    return current
}