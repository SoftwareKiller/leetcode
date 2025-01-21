func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }

    reverse := 0
    save := x
    for x > 0 {
        reverse = reverse * 10 + (x % 10)
        x /= 10
    }
    return reverse == save
}