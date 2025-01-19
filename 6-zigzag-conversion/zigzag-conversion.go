func convert(s string, numRows int) string {
    if len(s) <= 1 || numRows < 2  {
        return s
    }
    sSli := make([]string, numRows)
    next := 0
    add := -1
    for _, c := range s {
        sSli[next] += string(c)
        if next == 0 || next == numRows - 1{
            add = -add
        }
        next += add
    }

    ans := ""
    for _, subS := range sSli {
        ans += subS
    }
    return ans
}