class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l = 0, top = 0, bottom = matrix.size() - 1, r = matrix[0].size() - 1;

        while (top <= bottom && l <= r) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if (top <= bottom) {
                for (int i = r; i >= l; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (l <= r) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};