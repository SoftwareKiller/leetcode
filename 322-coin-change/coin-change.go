func coinChange(coins []int, amount int) int {
    memo := make([]int, amount + 1)

    var dp func(int)int
    dp = func(n int) int {
        if n == 0 {
            return 0
        }

        if n < 0 {
            return -1
        }

        if memo[n] != 0 {
            return memo[n]
        }

        ans := math.MaxInt
        for _, c := range coins {
            sub := dp(n - c)
            if sub == -1 {
                continue
            }
            ans = min(ans, 1 + sub)
        }

        if ans == math.MaxInt {
            ans = -1
        }

        memo[n] = ans

        return memo[n]
    }
    return dp(amount)
}