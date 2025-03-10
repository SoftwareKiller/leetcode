func findMin(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }

    l, r := 0, len(nums) - 1

    if nums[l] < nums[r] {
        return nums[l]
    }

    for l < r {
        mid := l + (r - l) >> 1

        if nums[mid] < nums[r] {
            r = mid
        } else if nums[mid] > nums[r] {
            l = mid + 1
        } else {
            r--
        }
    }

    return nums[r]
}