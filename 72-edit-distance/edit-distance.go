func minDistance(word1 string, word2 string) int {
    m, n := len(word1), len(word2)
    memo := make([][]int, m)

    for i := range memo {
        memo[i] = make([]int, n)
    }

    var dp func(int, int)int
    dp = func(i, j int) int {
        if i < 0 {
            return j + 1
        }

        if j < 0 {
            return i + 1
        }

        if memo[i][j] != 0 {
            return memo[i][j]
        }

        if word1[i] == word2[j] {
            memo[i][j] = dp(i-1, j-1)
        } else {
            memo[i][j] = min(dp(i-1, j - 1) + 1, min(dp(i-1, j) + 1, dp(i, j - 1) + 1))
        }

        return memo[i][j]
    }

    return dp(m-1, n-1)
}