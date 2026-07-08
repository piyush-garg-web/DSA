class Solution {
private:
    void solve(int col, int n, int& count, vector<string>& board,
               vector<bool>& rowCheck, vector<bool>& lowerDiagonalCheck,
               vector<bool>& upperDiagonalCheck) {
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!rowCheck[row] && !lowerDiagonalCheck[row + col] &&
                !upperDiagonalCheck[n - 1 + col - row]) {
                board[row][col] = 'Q';
                rowCheck[row] = 1;
                lowerDiagonalCheck[row + col] = 1;
                upperDiagonalCheck[n - 1 + col - row] = 1;
                solve(col + 1, n, count, board, rowCheck, lowerDiagonalCheck,
                      upperDiagonalCheck);
                board[row][col] = '.';
                rowCheck[row] = 0;
                lowerDiagonalCheck[row + col] = 0;
                upperDiagonalCheck[n - 1 + col - row] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        vector<bool> rowCheck(n, false);
        vector<bool> lowerDiagonalCheck(2 * n - 1, false);
        vector<bool> upperDiagonalCheck(2 * n - 1, false);
        solve(0, n, count, board, rowCheck, lowerDiagonalCheck, upperDiagonalCheck);
        return count;
    }
};