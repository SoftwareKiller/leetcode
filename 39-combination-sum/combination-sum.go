func combinationSum(candidates []int, target int) [][]int {
    ans := make([][]int, 0)
    comb := make([]int, 0)
    n := len(candidates)
    var backtrace func(int, int, []int)
    backtrace = func(t, start int, comb []int) {
        if t == 0 {
            temp := make([]int, len(comb))
            copy(temp, comb)
            ans = append(ans, temp)
            return
        }

        if t < 0 {
            return
        }

        for i := start; i < n; i++ {
            comb = append(comb, candidates[i])
            backtrace(t - candidates[i], i, comb)
            comb = comb[:len(comb)-1]
        }
    }
    backtrace(target, 0, comb)
    return ans
}