class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> memo(n+1, vector<bool>(m+1, false));
        function<bool(int, int)> dp = [&](int i, int j)->bool {
            // 备忘录已经计算过子问题
            if (memo[i][j]) {
                return memo[i][j];
            }

            // p匹配结束，s也应该匹配结束，否则不匹配
            if (j == m) {
                return i == n;
            }

            bool first = false;
            // 字符匹配或与.符号匹配
            // 这里只判断了i的边界，j的边界在上面已经隐含了初始合法的判断
            // 在下面提前做了入口规则的判断
            if ( i < n && (p[j] == s[i] || p[j] == '.')) {
                first = true;
            }
            bool ans = false;
            // *的规则为匹配任意长度个*号前字符
            // 因此如果为*号匹配，当前字符与s[i]相等，且下一个符号为*，j不变
            // 或*号匹配到终点，与下一个字符匹配，因此j+2
            if(j <= (m-2) && p[j+1] == '*') {
                ans = (dp(i, j + 2) || (first && dp(i+1, j)));
            } else {
                // 当前字符匹配，下一个字符
                ans = (first && dp(i+1, j+1));
            }
            memo[i][j] = ans;
            return ans;
        };
        return dp(0, 0);
    }
};