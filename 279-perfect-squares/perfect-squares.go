func numSquares(n int) int {
    nums := make([]int, 0)

    for i := 1; i < n; i++ {
        num := i * i
        if num > n {
            break
        }
        nums = append(nums, num)
    }

    dp := make([]int, n + 1)
    for i := range dp {
        dp[i] = n
    }

    dp[0] = 0
    for i := range dp {
        for _, num := range nums {
            if i - num < 0 {
                continue
            }
            dp[i] = min(dp[i], 1 + dp[i - num])
        }
    }

    return dp[n]
}