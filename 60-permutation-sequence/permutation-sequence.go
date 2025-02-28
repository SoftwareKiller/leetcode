func getPermutation(n int, k int) string {
    fact := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        if fact[i - 1] == 0 {
            fact[i-1] = 1
        }
        fact[i] = fact[i - 1] * i
    }

    ans := ""
    used := make([]bool, n + 1)
    for i := 0; i < n; i++ {
        cnt := fact[n - i - 1]
        for j := 1; j <= n; j++ {
            if used[j] {
                continue
            }

            if k > cnt {
                k -= cnt
            } else {
                ans += string(j + '0')
                used[j] = true
                break
            }
        }
    }
    return ans
}