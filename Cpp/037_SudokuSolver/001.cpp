class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
private:
    bool dfs(vector<vector<char>>& board, int row, int column) {
        if (row == 9) {
            return true;
        } else if (column == 9) {
            return dfs(board, row + 1, 0);
        }
        if (board[row][column] == '.') {
            for (char ch = '1'; ch <= '9'; ++ch) {
                board[row][column] = ch;
                if (isValid(board, row, column) && dfs(board, row, column + 1)) {
                    return true;
                }
            }
            board[row][column] = '.';
            return false;
        } else {
            return dfs(board, row, column + 1);
        }
    }
    bool isValid(vector<vector<char>>& board, int row, int column) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][column] == board[row][column]) {
                return false;
            }
        }
        for (int j = 0; j < 9; ++j) {
            if (j != column && board[row][j] == board[row][column]) {
                return false;
            }
        }
        for (int i = row / 3 * 3; i < row / 3 * 3 + 3; ++i) {
            for (int j = column / 3 * 3; j < column / 3 * 3 + 3; ++j) {
                if ((i != row || j != column) && board[i][j] == board[row][column]) {
                    return false;
                }
            }
        }
        return true;
    }
};