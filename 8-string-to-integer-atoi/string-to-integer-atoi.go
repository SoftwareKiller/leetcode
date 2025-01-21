func myAtoi(s string) int {
    sign := 1
    n := len(s)
    i := 0
    for ; i < n; i++ {
        if !unicode.IsSpace(rune(s[i])) {
            break
        }
    }
    if i < n && s[i] == '+' {
        sign = 1
        i++
    } else if i < n && s[i] == '-' {
        sign = -1
        i++
    }

    ans := 0
    for ; i < n; i++ {
        if s[i] < '0' || s[i] > '9' {
            break
        }
        v := s[i] - '0'
        ans = ans * 10 + int(v)
        if sign == 1 && ans > math.MaxInt32 {
            return int(math.MaxInt32)
        }
        if sign == -1 && (ans * sign) < math.MinInt32 {
            return int(math.MinInt32)
        } 
    }
    return ans * sign
}