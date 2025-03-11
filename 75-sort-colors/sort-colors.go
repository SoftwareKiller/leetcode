func sortColors(nums []int)  {
    l, mid, r := 0, 0, len(nums) - 1

    for mid <= r {
        if nums[mid] == 0 {
            nums[mid], nums[l] = nums[l], nums[mid]
            l++
            mid++
        } else if nums[mid] == 2 {
            nums[mid], nums[r] = nums[r], nums[mid]
            r--
        } else {
            mid++
        }
    }
}