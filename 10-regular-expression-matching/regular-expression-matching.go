func isMatch(s string, p string) bool {
    n, m := len(s), len(p)
    // dp[i][j]表示截至i的字符串s和截至j的匹配字符p是否相匹配
    dp := make([][]bool, n + 1)
    for i := range dp {
        dp[i] = make([]bool, m + 1)
    }
    dp[0][0] = true
    for i := 0; i <= n; i++ {
        for j := 1; j <= m; j++ {
            // 对j的边界不做判断是因为规则最后一条为p[j-1]为*则之前必定有有效字符
            if p[j-1] == '*' {
                // dp[i][j-2]判断当前*是否已经匹配结束
                // dp[i-1][j]判断当前*的前一个字符是否匹配
                dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.')) && dp[i-1][j]
            } else {
                dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
            }
        }
    }
    return dp[n][m]
}