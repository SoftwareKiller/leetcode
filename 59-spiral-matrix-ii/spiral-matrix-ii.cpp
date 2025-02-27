class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int count = 1;
        int l = 0, r = n - 1, top = 0, bottom = n - 1;
        while (l <= r && top <= bottom) {
            for (int i = l; i <= r; i++) {
                ans[top][i] = count++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans[i][r] = count++;
            }
            r--;

            if (l <= r) {
                for (int i = r; i >= l; i--) {
                    ans[bottom][i] = count++;
                }
                bottom--;
            }

            if (top <= bottom) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][l] = count++;
                }
                l++;
            }
        }
        return ans;
    }
};