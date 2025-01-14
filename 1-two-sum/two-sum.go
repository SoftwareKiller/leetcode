func twoSum(nums []int, target int) []int {
    hash := make(map[int]int)
    for i, v := range nums {
        x := target - v
        index, ok := hash[x]
        if ok {
            return []int{index, i}
        }
        hash[v] = i
    }
    return []int{}
}