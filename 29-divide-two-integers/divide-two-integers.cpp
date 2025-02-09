class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        bool flag = ((dividend > 0) == (divisor > 0));
        unsigned int ans = 0;

        int64_t dd = abs((long long)dividend);
        int64_t dr = abs((long long)divisor);
        while (dd >= dr) {
            int64_t i = 0;
            while(((int64_t)1 << (i+1)) * dr < dd) {
                i++;
            }
            ans += (1 << i);
            dd -= (1<<i) * dr;
        }
        cout << flag << endl;
        if (flag) {
           if (ans > INT_MAX) {
               return INT_MAX;
           }
           return ans;
        }
        return -ans;
    }
};