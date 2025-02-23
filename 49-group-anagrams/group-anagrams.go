func groupAnagrams(strs []string) [][]string {
    ans := make([][]string, 0)
    hash := make(map[string][]string, 0)

    for _, str := range strs {
        t := []rune(str)
        sort.Slice(t, func(i, j int) bool { return t[i] > t[j] })
        hash[string(t)] = append(hash[string(t)], str)
    }

    for _, sts := range hash {
        ans = append(ans, sts)
    }
    return ans
}