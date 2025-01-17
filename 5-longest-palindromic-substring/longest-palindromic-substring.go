func longestPalindrome(s string) string {
    n := len(s)
    if n < 2 {
        return s
    }

    // dp[l][r]表示从l到r是否为回文
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
    }

    maxL, start, end := 1, 0, 0
    for r := 1; r < n; r++ {
        for l := 0; l < r; l++ {
            // dp[l][r] = dp[l+1][r-1] 递归
            if s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1]) {
                dp[l][r] = true
                if r - l + 1 > maxL {
                    maxL = r - l
                    start = l
                    end = r
                }
            }
        }
    }
    return s[start:end+1]
}