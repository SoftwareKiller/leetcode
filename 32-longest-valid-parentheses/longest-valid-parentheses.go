func longestValidParentheses(s string) int {
    st := make([]int, 0)
    ans := 0
    st = append(st, -1)
    for i, c := range s {
        if c == '(' {
            st = append(st, i)
        } else {
            st = st[0:len(st)-1]
            if len(st) == 0 {
                st = append(st, i)
            } else {
                ans = max(ans, i - st[len(st)-1])
            }
        }
    }
    return ans
}