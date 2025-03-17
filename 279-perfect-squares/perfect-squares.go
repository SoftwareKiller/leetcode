func numSquares(n int) int {
    dp := make([]int, n + 1)
    for i := range dp {
        dp[i] = n
    }

    dp[0] = 0
    for i := 1; i <= n; i++ {
        num := math.MaxInt
        for j := 1; j * j <= i; j++ {
            num= min(num, 1 + dp[i - j * j])
        }
        dp[i] = num
    }

    return dp[n]
}