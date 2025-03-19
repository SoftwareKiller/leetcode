class Solution {
public:
    bool isScramble(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int n = s.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = s[i] == t[j];
            }
        }

        for (int k = 2; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (!check(s, t, i, j, k)) {
                        dp[i][j][k] = false;
                        continue;
                    }

                    bool flag = false;
                    for (int k1 = 1; k1 < k && !flag; k1++) {
                        // 不交换
                        int case1 = dp[i][j][k1] && dp[i+k1][j+k1][k-k1];
                        // 交换
                        int case2 = dp[i][j+(k-k1)][k1] && dp[i+k1][j][k-k1];
                        flag = case1 || case2;
                    }
                    dp[i][j][k] = flag;
                }
            }
        }
        return dp[0][0][n];
    }

    bool check(string s, string t, int i, int j, int k) {
        vector<int> cnt(26);

        for (int p = 0; p < k; p++) {
            cnt[s[i + p] - 'a']++;
            cnt[t[j + p] - 'a']--;
        }

        for (int c : cnt) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};