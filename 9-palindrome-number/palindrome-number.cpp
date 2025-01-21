class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> num;
        while(x) {
            int v = x % 10;
            x /= 10;
            num.push_back(v);
        }

        int l = 0, r = num.size() - 1;
        while (l < r) {
            if (num[l] != num[r]) {
                return false;
            }
            l++, r--;
        }
        return true;
    }
};