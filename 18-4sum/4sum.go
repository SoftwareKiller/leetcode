func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)

    ans := make([][]int, 0)
    n := len(nums)
    for i := 0; i < n - 3; i++ {
        if i != 0 && nums[i-1] == nums[i] {
            continue
        }
        for j := i + 1; j < n - 2; j++ {
            if j != i + 1 && nums[j-1] == nums[j] {
                continue
            }
            low := j + 1
            high := n - 1
            for low < high {
                sum := nums[i] + nums[j] + nums[low] + nums[high]
                if sum < target {
                    low++
                } else if sum > target {
                    high--
                } else {
                    ans = append(ans, []int{nums[i], nums[j], nums[low], nums[high]})
                    low++
                    for low < high && nums[low-1] == nums[low] {
                        low++
                    }
                }
            }
        }
    }
    return ans
}