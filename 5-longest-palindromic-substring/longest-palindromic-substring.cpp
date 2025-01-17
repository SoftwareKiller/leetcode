class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        int maxL = 1, b = 0, e = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

        for(int r = 1; r < n; ++r) {
            for(int l = 0; l < r; ++l) {
                if(s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    if (r - l + 1 > maxL) {
                        maxL = r - l;
                        b = l;
                        e = r;
                    }
                }
            }
        }

        return s.substr(b, e - b + 1);
    }
};