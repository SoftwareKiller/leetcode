func generateParenthesis(n int) []string {
    ans := make([]string, 0)
    var dfs func(int, int, string)
    dfs = func(l, r int, p string) {
        if l == r && l + r == 2 * n {
            ans = append(ans, p)
        }

        if l < n {
            dfs(l + 1, r, p + "(")
        }

        if r < l {
            dfs(l, r + 1, p + ")")
        }
    }
    dfs(0, 0, "")
    return ans
}