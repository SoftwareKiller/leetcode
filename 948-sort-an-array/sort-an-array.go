func sortArray(nums []int) []int {
    n := len(nums)

    for i := n/2 - 1; i >= 0; i-- {
        adjust(nums, n, i)
    }

    for i := n - 1; i >= 0; i-- {
        nums[0], nums[i] = nums[i], nums[0]
        adjust(nums, i, 0)
    }

    return nums
}

func adjust(nums []int, n, i int) {
    largest := i
    l := 2 * i + 1
    r := 2 * i + 2

    if l < n && nums[l] > nums[largest] {
        largest = l
    }

    if r < n && nums[r] > nums[largest] {
        largest = r
    }

    if largest != i {
        nums[i], nums[largest] = nums[largest], nums[i]
        adjust(nums, n, largest)
    }
}