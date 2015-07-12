class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //actually don't need this, since the problem has mentioned that there is only one valid solution
        if (board.size() == 0 || board[0].size() != 9) {
            return;
        }
        helper(board, 0, 0);
    }
private:
    bool helper(vector<vector<char>>& board, int row, int column) {
        if (column == 9) {
            return helper(board, row + 1, 0);
        }
        if (row == 9) {
            return true;
        }
        if (board[row][column] == '.') {
            for (int i = 1; i <= 9; ++i) {
                board[row][column] = i + '0';
                if (isValid(board, row, column)) {
                    if (helper(board, row, column + 1)) {
                        return true;
                    }
                }
            }
            board[row][column] = '.';//don't put this line into the for loop, 恢复现场
        } else {
            if (helper(board, row, column + 1)) {
                return true;
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int row, int column) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][column] == board[row][column]) {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (i != column && board[row][i] == board[row][column]) {
                return false;
            }
        }
        for (int i = row / 3 * 3; i < row / 3 * 3 + 3; ++i) {
            for (int j = column / 3 * 3; j < column / 3 * 3 + 3; ++j) {//I misuse j < row / 3 * 3 + 3, take more than 3 hrs to debug...
                if ((i != row || j != column) && board[i][j] == board[row][column]) {
                    return false;
                }
            }
        }
        return true;
    }
};
