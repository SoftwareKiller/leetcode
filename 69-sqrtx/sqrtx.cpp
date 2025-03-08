class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }

        int64_t ans = 1;
        while (ans < x) {
            if ((ans*2) * (ans*2) <= x) {
                ans *= 2;
                continue;
            }

            if ((ans+1) * (ans+1) <= x) {
                ans++;
                continue;
            }
            break;
        }
        return ans;
    }
};