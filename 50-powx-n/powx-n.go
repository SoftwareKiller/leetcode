func myPow(x float64, n int) float64 {
    return binEx(x, n)
}

func binEx(x float64, n int) float64 {
    if n == 0 {
        return 1.0
    }

    if n < 0 {
        return 1.0 / binEx(x, -n)
    }

    if n % 2 == 1 {
        return x * binEx(x * x, (n-1)/2)
    }

    return binEx(x * x, n/2) 
}