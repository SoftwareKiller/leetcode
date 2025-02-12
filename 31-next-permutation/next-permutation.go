func nextPermutation(nums []int)  {
    n := len(nums)
    i := n - 2
    for i >= 0 && nums[i] >= nums[i+1] {
        i--
    }

    if i >= 0 {
        j := n - 1
        for j >= 0 && nums[j] <= nums[i] {
            j--
        }

        if (j >= 0) {
            nums[i], nums[j] = nums[j], nums[i]
        }
    }

    offset := 0
    for l := i + 1; l < n - offset - 1; l++ {
        nums[l], nums[n-offset-1] = nums[n-offset-1], nums[l]
        offset++
    }
}