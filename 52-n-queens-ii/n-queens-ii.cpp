class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        backtrace(ans, board, 0);
        return ans;
    }

    bool valid(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrace(int& ans, vector<string>& board, int row) {
        if (row == board.size()) {
            ans++;
            return;
        }

        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (!valid(board, row, i)) {
                continue;
            }
            board[row][i] = 'Q';
            backtrace(ans, board, row+1);
            board[row][i] = '.';
        }
    }
};