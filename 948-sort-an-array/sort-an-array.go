func sortArray(nums []int) []int {
    mergeSort(nums, 0, len(nums) - 1)
    return nums
}

func mergeSort(nums []int, l, r int) {
    if l >= r {
        return
    }

    mid := ((r - l) >> 1) + l
    mergeSort(nums, l, mid)
    mergeSort(nums, mid + 1, r)

    merge(nums, l, mid, r)
}

func merge(nums []int, l, mid, r int) {
    i, j := l, mid + 1
    curr := 0

    t := make([]int, r - l + 1)

    for i <= mid && j <= r {
        if nums[i] < nums[j] {
            t[curr] = nums[i]
            i++
        } else {
            t[curr] = nums[j]
            j++
        }
        curr++
    }

    for i <= mid {
        t[curr] = nums[i]
        curr++
        i++
    }

    for j <= r {
        t[curr] = nums[j]
        curr++
        j++
    }

    i = l
    for offset, n := range t {
        nums[i+offset] = n
    }
}