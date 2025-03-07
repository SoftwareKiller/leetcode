func lengthOfLIS(nums []int) int {
    if len(nums) <= 0 {
        return 0
    }

    arr := make([]int, 0)
    for _, x := range nums {
        i := sort.SearchInts(arr, x)
        if i == len(arr) {
            arr = append(arr, x)
        } else {
            arr[i] = x
        }
    }

    return len(arr)
}