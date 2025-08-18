
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        // O(1) occupancy trackers
        vector<int> rows(n, 0);
        vector<int> lowerDiag(2*n - 1, 0);           // row + col
        vector<int> upperDiag(2*n - 1, 0);           // (n - 1) + col - row

        placeCol(0, n, board, rows, lowerDiag, upperDiag, ans);
        return ans;
    }

private:
    void placeCol(int col,
                  int n,
                  vector<string>& board,
                  vector<int>& rows,
                  vector<int>& lowerDiag,
                  vector<int>& upperDiag,
                  vector<vector<string>>& ans) {
        if (col == n) {
            ans.emplace_back(board);
            return;
        }
        for (int r = 0; r < n; ++r) {
            int ld = r + col;
            int ud = (n - 1) + col - r;
            if (!rows[r] && !lowerDiag[ld] && !upperDiag[ud]) {
                // place
                board[r][col] = 'Q';
                rows[r] = lowerDiag[ld] = upperDiag[ud] = 1;

                placeCol(col + 1, n, board, rows, lowerDiag, upperDiag, ans);

                // remove
                board[r][col] = '.';
                rows[r] = lowerDiag[ld] = upperDiag[ud] = 0;
            }
        }
    }
};
