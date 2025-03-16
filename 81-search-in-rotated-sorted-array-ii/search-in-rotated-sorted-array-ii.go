func search(nums []int, target int) bool {
    l := 0
    r := len(nums) - 1
    for l <= r {
        mid := ((r-l) >> 1) + l

        if nums[mid] == target {
            return true
        }

        if nums[l] == nums[mid] {
            l++
            continue
        }

        if nums[mid] <= nums[r] {
            if nums[mid] < target && target <= nums[r] {
                l = mid + 1
            } else {
                r = mid - 1
            }
        } else {
            if nums[l] <= target && target < nums[mid] {
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
    }

    return false
}