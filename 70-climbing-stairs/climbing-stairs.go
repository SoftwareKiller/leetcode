func climbStairs(n int) int {
    // dp[i] = dp[i-1] + dp[i-2]，当前台阶为n，到达n的前两阶只会有n-1或n-2两种情况
    if n <= 2 {
        return n
    }
    
    step1, step2 := 1, 2
    curr := 0
    for step := 3; step <= n; step++ {
        curr = step1 + step2
        step1 = step2
        step2 = curr
    }
    return curr
}