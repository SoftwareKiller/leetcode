func coinChange(coins []int, amount int) int {
    // dp[i]表示，金额为i时，最少可用的金币
    dp := make([]int, amount + 1)

    for i := range dp {
        dp[i] = amount + 1
    }

    dp[0] = 0

    for i := range dp {
        for _, c := range coins {
            if i - c < 0 {
                continue
            }
            dp[i] = min(dp[i], dp[i-c] + 1)
        }
    }

    if dp[amount] == amount + 1 {
        return -1
    }
    return dp[amount]
}