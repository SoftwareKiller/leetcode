class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int al = a.length() - 1;
        int bl = b.length() - 1;
        while (al >= 0 || bl >= 0 || carry) {
            if (al >= 0) carry += a[al--] - '0';
            if (bl >= 0) carry += b[bl--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};