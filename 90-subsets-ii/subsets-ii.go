func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)

    ans := make([][]int, 0)
    var backtrace func(int,[]int)
    backtrace = func(i int, set []int) {
        if i >= len(nums) {
            t := make([]int, len(set))
            copy(t, set)
            ans = append(ans, t)
            return
        }

        set = append(set, nums[i])
        backtrace(i + 1, set)
        set = set[:len(set)-1]

        for i + 1 < len(nums) && nums[i] == nums[i+1] {
            i++
        }

        backtrace(i + 1, set)
    }
    backtrace(0, []int{})
    return ans
}