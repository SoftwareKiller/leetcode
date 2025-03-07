func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return 0
    }

    maxArea := 0
    rows, cols := len(matrix), len(matrix[0])
    height := make([]int, cols)
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if matrix[i][j] == '1' {
                height[j]++
            } else {
                height[j] = 0
            }
        }

        curr := maxRectangle(height)
        if curr > maxArea {
            maxArea = curr
        }
    }
    return maxArea
}

/*
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]
转换为
["3","1","3","2","2"]
*/

func maxRectangle(height []int) int {
    n := len(height)

    stack := []int{-1}
    maxArea := 0
    for i := 0; i < n; i++ {
        for len(stack) > 1 && height[i] < height[stack[len(stack)-1]] {
            t := stack[len(stack)-1]
            fmt.Println(t)
            stack = stack[:len(stack)-1]
            w := i - stack[len(stack)-1] - 1
            area := height[t] * w
            if area > maxArea {
                maxArea = area
            }
        }
        stack = append(stack, i)
    }

    for len(stack) > 1 {
        t := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        w := n - stack[len(stack)-1] - 1
        area := height[t] * w
        if area > maxArea {
            maxArea = area
            fmt.Println(area)
        }
    }
    return maxArea
}