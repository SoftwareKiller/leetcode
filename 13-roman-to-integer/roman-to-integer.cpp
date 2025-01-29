class Solution {
public:
    int romanToInt(string s) {
        string symbol[] = {"M", "D", "C", "L", "X", "V", "I"};
        string symbolCal[] = {"CM", "CD", "XC", "XL", "IX", "IV"};
        int val[] = {1000, 500, 100, 50, 10, 5, 1};
        int valCal[] = {900, 400, 90, 40, 9, 4};
        int ans = 0;
        int l = s.length();
        int pos = 0;
        while (pos < l) {
            for (int i = 0; i < sizeof(symbolCal) / sizeof(symbolCal[0]); i++) {
                while (pos + 1 < l && s.substr(pos, 2) == symbolCal[i]) {
                    ans += valCal[i];
                    pos += 2;
                }
            }

            for (int i = 0; i < sizeof(symbol) / sizeof(symbol[0]); i++) {
                if (pos < l && s.substr(pos, 1) == symbol[i]) {
                    ans += val[i];
                    pos++;
                    break;
                }
            }
        }
        return ans;
    }
};