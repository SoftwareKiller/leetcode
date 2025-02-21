class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();

        int top = 0;
        int bottom = l - 1;

        while(top < bottom) {
            for (int col = 0; col < l; col++) {
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }

        for (int row = 0; row < l; row++) {
            for (int col = row + 1; col < l; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};