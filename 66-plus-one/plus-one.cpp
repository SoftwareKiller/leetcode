class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        if (digits.back() != 9) {
            ans = digits;
            ans[ans.size()-1]++;
            return ans;
        }

        int n = digits.size();
        int hit = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                hit++;
            } else {
                break;
            }
        }

        if (hit == n) {
            ans.resize(n+1, 0);
            ans[0] = 1;
            return ans;
        }

        cout << hit;

        ans = digits;
        for (int i = 0; i < hit; i++) {
            ans[n-i-1] = 0;
        }
        ans[n-hit-1]++;
        return ans;
    }
};