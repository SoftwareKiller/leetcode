class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int l = 1, r = x;
        int64_t mid = -1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            int64_t square = mid * mid;
            if (square == x) {
                return mid;
            }

            if (square > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }
};