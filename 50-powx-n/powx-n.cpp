class Solution {
public:
    double myPow(double x, int n) {
        return binEx(x, static_cast<long>(n));
    }

    double binEx(double x, long n) {
        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            return 1.0 / binEx(x, -n);
        }

        if (n % 2 == 1) {
            return x * (binEx(x * x, (n-1)/2));
        }

        return binEx(x*x, n / 2);
    }
};