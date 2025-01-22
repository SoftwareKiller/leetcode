func maxArea(height []int) int {
    left, right := 0, len(height) - 1
    maxArea := 0
    for left < right {
        maxArea = max(maxArea, (right - left) * min(height[left], height[right]))

        if (height[left] < height[right]) {
            left++
        } else {
            right--
        }
    }

    return maxArea
}