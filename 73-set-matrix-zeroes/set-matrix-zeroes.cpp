class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, vector<int>> row2col;

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                if (matrix[row][col] == 0) {
                    row2col[row].push_back(col);
                }
            }
        }

        for (auto& it : row2col) {
            int row = it.first;
            vector<int>& cols = it.second;

            for (int i = 0; i < matrix[row].size(); i++) {
                matrix[row][i] = 0;
            }

            for (int col : cols) {
                for (int row = 0; row < matrix.size(); row++) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};