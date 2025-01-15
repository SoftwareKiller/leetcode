func lengthOfLongestSubstring(s string) int {
    left := 0
    window := make(map[rune]bool)
    ans := 0
    for right, c := range s {
        for window[c] {
            delete(window, rune(s[left]))
            left++
        }
        window[c] = true
        ans = max(ans, right - left + 1)
    }
    return ans
}