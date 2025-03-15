func sortArray(nums []int) []int {
    quicksort(nums, 0, len(nums) - 1)
    return nums
}

func mid(nums []int, l, r int) int {
    mid := ((r - l) >> 1) + l
    if nums[l] <= nums[mid] && nums[mid] < nums[r] {
        return mid
    }

    if nums[mid] <= nums[l] && nums[l] <= nums[r] {
        return l
    }

    return r
}

func quicksort(nums []int, l, r int) {
    if l >= r {
        return
    }

    midNum := mid(nums, l, r)
    nums[l], nums[midNum] = nums[midNum], nums[l]

    i, j := l, r
    for i < j {
        for i < j && nums[j] >= nums[l] {
            j--
        }

        for i < j && nums[i] <= nums[l] {
            i++
        }
        nums[i], nums[j] = nums[j], nums[i]
    }

    nums[l], nums[i] = nums[i], nums[l]
    quicksort(nums, l, i - 1)
    quicksort(nums, i + 1, r)
}