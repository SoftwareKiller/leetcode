class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int aL = a.length() - 1, bL = b.length() - 1;
        char carry = '0';
        while(aL >= 0 || bL >= 0 || carry != '0') {
            char s1 = '0', s2 = '0';
            if (aL >= 0) {
                s1 = a[aL--];
            }

            if (bL >= 0) {
                s2 = b[bL--];
            }

            char curr = '0';
            if (s1 == '1' && s2 == '1') {
                if (carry == '1') {
                    curr = '1';
                } else {
                    curr = '0';
                    carry = '1';
                }
            } else {
                if (carry == '1') {
                    if (s1 == '0' && s2 == '0') {
                        curr = '1';
                        carry = '0';
                    }
                } else {
                    if (s1 == '1' || s2 == '1') {
                        curr = '1';
                    }
                }
            }
            ans.push_back(curr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};