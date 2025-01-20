class Solution {
public:
    int myAtoi(string s) {
        int64_t ans = 0;
        bool flag = false;
        bool begin = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (begin) {
                    break;
                }
                begin = true;
                if(s[i] == '-') {
                    flag = true;
                }
                continue;
            }

            if (s[i] < '0' || s[i] > '9') {
                if ((isspace(s[i])) && !begin) {
                    continue;
                }
                break;
            }
            int num = s[i] - '0';
            ans = ans * 10 + num;
            if (ans > -static_cast<int64_t>(INT_MIN)) {
                break;
            }
            begin = true;
        }
        if (flag) {
            ans = -ans;
        }

         if (ans > INT_MAX) {
            ans = INT_MAX;
        }

        if (ans < INT_MIN) {
            ans = INT_MIN;
        }

        return static_cast<int>(ans);
    }
};