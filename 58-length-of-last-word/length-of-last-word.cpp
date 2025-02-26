class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!isspace(s[i])) {
                ans++;
                continue;
            }

            if (ans != 0) {
                break;
            }
        }
        return ans;
    }
};