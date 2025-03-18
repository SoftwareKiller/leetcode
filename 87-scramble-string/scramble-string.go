func isScramble(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }

    n := len(s1)

    // dp[i][j][k] 表示长度为从i开始长度为k的字符串能否变化为从j开始长度为k的字符串
    dp := make([][][]bool, n)
    for i := range dp {
        dp[i] = make([][]bool, n)
        for j := range dp[i] {
            dp[i][j] = make([]bool, n + 1)
            dp[i][j][1] = s1[i] == s2[j]
        }
    }

    for k := 2; k <= n; k++ {
        for i := 0; i <= n - k; i++ {
            for j := 0; j <= n - k; j++ {
                if !checkChars(s1, s2, i, j, k) {
                    dp[i][j][k] = false
                    continue
                }

                flag := false
                // 遍历分割点
                for k1 := 1; k1 < k && !flag; k1++ {
                    // 不交换
                    case1 := dp[i][j][k1] && dp[i+k1][j+k1][k-k1]
                    // 交换
                    case2 := dp[i][j+(k-k1)][k1] && dp[i+k1][j][k-k1]
                    flag = case1 || case2
                }
                dp[i][j][k] = flag
            }
        }
    }
    return dp[0][0][n]
}

func checkChars(s, t string, i, j, k int) bool {
    cnt := [26]int{}
    for p := 0; p < k; p++ {
        cnt[s[i+p] - 'a']++
        cnt[t[j+p] - 'a']--
    }

    for _, v := range cnt {
        if v != 0 {
            return false
        }
    }

    return true
}