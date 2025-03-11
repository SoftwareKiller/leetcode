func trap(height []int) int {
    st := make([]int, 0)
    ans := 0

    for i, h := range height {
        for len(st) > 0 && h >= height[st[len(st) - 1]] {
            t := st[len(st) - 1]
            st = st[:len(st)-1]
            if (len(st) == 0) {
                break
            }
            l := st[len(st)-1]
            sub := min(height[l], h) - height[t]
            ans += (i - l - 1) * sub
        }

        st = append(st, i)
    }

    return ans
}