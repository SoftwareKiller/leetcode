class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        // 输入有字符,空格和符号，ASCII
        unordered_set<char> set;
        for(int right = 0; right < s.length(); right++) {
            char c = s.at(right);
            while(left < right && (set.find(c) != set.end())) {
                set.erase(s.at(left));
                left++;
            }
            set.insert(c);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};