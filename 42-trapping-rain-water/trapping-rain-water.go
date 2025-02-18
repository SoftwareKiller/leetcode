func trap(height []int) int {
    l, r := 0, len(height) - 1
    lMax, rMax := height[l], height[r]
    water := 0

    for l < r {
        if lMax < rMax {
            l++
            lMax = max(lMax, height[l])
            water += lMax - height[l]
        } else {
            r--
            rMax = max(rMax, height[r])
            water += rMax - height[r]
        }
    }

    return water
}