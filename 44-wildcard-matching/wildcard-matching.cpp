class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j]，含义为从s[i]到p[j]是否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};