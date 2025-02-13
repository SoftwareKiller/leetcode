class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return vaildRow(board) && vaildCol(board) && subBoard(board);
    }

    bool vaildRow(vector<vector<char>>& board) {
        for (auto& row : board) {
            vector<char> v(10);
            for(auto c : row) {
                if (c <= '0' || c > '9') {
                    continue;
                }
                v[c-'0']++;
                if (v[c-'0'] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool vaildCol(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<char> v(10);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c <= '0' || c > '9') {
                    continue;
                }
                v[c-'0']++;
                if (v[c-'0'] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool subBoard(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                vector<char> v(10);
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        char c = board[x][y];
                        if (c <= '0' || c > '9') {
                            continue;
                        }
                        v[c-'0']++;
                        if (v[c-'0'] > 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};