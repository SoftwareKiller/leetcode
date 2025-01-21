func isMatch(s string, p string) bool {
    n, m := len(s), len(p)
    // dp[i][j]表示截至i的s与截至j的p是否匹配
    dp := make([][]bool, n+1)
    for i := range dp {
        dp[i] = make([]bool, m+1)
    }
    dp[0][0] = true
    for i := 0; i <= n; i++ {
        for j := 1; j <= m; j++ {
            // 不对j进行边界判断是规则最后一条明确*之前必须有合法字符
            if p[j-1] == '*' {
                // 
                dp[i][j] = dp[i][j-2] || ( i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.')) && dp[i-1][j]
            } else {
                dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
            }
        }
    }
    return dp[n][m]
}