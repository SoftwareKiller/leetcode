class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows <= 1 || n <= numRows) return s;

        int cycle = (numRows - 1) << 1;  // 循环周期，2 * (nuwRows - 1)
        string ans(n, '\0');
        int idx = 0;

        for(int r = 0; r < numRows; r++) {
            for(int i = r; i < n; i += cycle) {
                ans[idx++] = s[i];  // 按周期更新每行的字符

                if(r > 0 && r < numRows - 1) {
                    int j = i + cycle - (r << 1);
                    if(j < n) ans[idx++] = s[j];
                }
            }
        }

        return ans;
    }
};