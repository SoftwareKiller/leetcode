class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> map(128, 0);
        int count = t.length();
        int l = 0, r = 0, minLen = INT_MAX, i = 0;
        for (char c : t) {
            map[c]++;
        }

        while(r < s.length()) {
            if (map[s[r++]]-- > 0) {
                count--;
            }

            while(count == 0) {
                if (r - l < minLen) {
                    i = l;
                    minLen = r - l;
                }

                if (map[s[l++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(i, minLen);
    }
};