func sortArray(nums []int) []int {
    count := make([]int, 100001)

    const offset = 50000

    for _, n := range nums {
        if n < 0 {
            n += offset
            count[n]++
        } else {
            count[n+offset]++
        }
    }

    ans := make([]int, len(nums))
    curr := 0
    for i, cnt := range count {
        if cnt == 0 {
            continue
        }

        for j := 0; j < cnt; j++ {
            n := i - offset
            if i < 0 {
                ans[curr] = n
            } else {
                ans[curr] = n
            }
            curr++
        }
    }

    return ans
}