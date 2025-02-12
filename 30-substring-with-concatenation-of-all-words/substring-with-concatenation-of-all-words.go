func findSubstring(s string, words []string) []int {
    ans := make([]int, 0)
    if len(s) == 0 || len(words) == 0 {
        return ans
    }

    word2int := make(map[string]int, 0)
    for _, w := range words {
        word2int[w]++
    }

    length := len(words[0])
    n := len(s)
    for offset := 0; offset < length; offset++ {
        windows := make(map[string]int)
        left := offset
        size := 0
        for i := offset; i <= n - length; i+=length {
            sub := s[i:i+length]
            count, ok := word2int[sub]
            if !ok {
                windows = make(map[string]int)
                size = 0
                left = i + length
                continue
            }
            windows[sub]++
            size++
            for windows[sub] > count {
                move := s[left:left+length]
                windows[move]--
                size--
                left += length
            }

            if size == len(words) {
                ans = append(ans, left)
            }
        }
    }
    return ans
}