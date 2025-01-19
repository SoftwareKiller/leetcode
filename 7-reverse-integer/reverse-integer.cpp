class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        int64_t ans = x;
        if (ans < 0) {
            flag = true;
            ans = -ans;
        }

        vector<int> num;
        bool first = true;
        while(ans) {
            int v = ans % 10;
            ans /= 10;
            if (v == 0 && first) {
                continue;
            }
            first = false;
            num.push_back(v);
        }
        for(int v : num) {
            if (ans > 0) {
                ans *= 10;
            }
            ans += v;
            if (ans > INT_MAX) return 0;
        }

        if (flag) {
            ans = -ans;
        }

        if (ans < INT_MIN) {
            return 0;
        }
        
        return static_cast<int>(ans);
    }
};