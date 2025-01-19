class Solution {
public:
    int reverse(int x) {
        int64_t ans = 0;
        while(x) {
            int v = x % 10;
            ans = ans * 10 + v;
            if (ans > INT_MAX || ans < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return static_cast<int>(ans);
    }
};