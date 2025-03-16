func largestRectangleArea(heights []int) int {
    st := make([]int, 0)
    st = append(st, -1);
    n := len(heights)
    ans := 0

    for i, h := range heights {
        for len(st) > 1 && heights[st[len(st)-1]] > h {
            t := st[len(st)-1]
            st = st[:len(st)-1]
            w := i - st[len(st)-1] - 1
            area := w * heights[t]
            ans = max(ans, area)
        }
        st = append(st, i)
    }

    for len(st) > 1 {
        t := st[len(st)-1]
        st = st[:len(st)-1]
        w := n - st[len(st)-1] - 1
        area := w * heights[t]
        ans = max(ans, area)
    }

    return ans
}