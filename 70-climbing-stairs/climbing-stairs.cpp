class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }

        int a = 1, b = 2;
        int c = 3;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};