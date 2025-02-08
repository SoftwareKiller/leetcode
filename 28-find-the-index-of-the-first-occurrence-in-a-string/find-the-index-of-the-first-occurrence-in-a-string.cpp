class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        for (int i = 0; i < n; i++) {
            if (haystack[i] != needle[0]) {
                continue;
            }

            bool eq = true;
            for (int j = 0; j < needle.length(); j++) {
                if (i + j >= n) {
                    return -1;
                }

                if (haystack[i+j] != needle[j]) {
                    eq = false;
                    break;
                }
            }
            if (eq) {
                return i;
            }
        }
        return -1;
    }
};