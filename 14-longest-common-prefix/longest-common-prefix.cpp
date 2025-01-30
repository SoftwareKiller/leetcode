class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int index = 0;
        int size = strs.size();
        bool end = false;
        while(1) {
            char c = 0;
            for(int i = 0; i < size; i++) {
                const string& s = strs[i];
                if (s.length() <= index) {
                    end = true;
                    break;
                }
                if (c == 0) {
                    c = s[index];
                }

                if (s[index] != c) {
                    end = true;
                    break;
                }
            }

            if (end) {
                break;
            }
            ans += c;
            ++index;
        }
        return ans;
    }
};