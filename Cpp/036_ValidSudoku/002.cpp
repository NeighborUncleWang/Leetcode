class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> result(9, false);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (result[board[i][j] - '1'] == true) {
                        return false;
                    }
                    result[board[i][j] - '1'] = true;
                }
            }
            result = vector<bool>(9, false);
        }
        for (int j = 0; j < 9; ++j) {
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (result[board[i][j] - '1'] == true) {
                        return false;
                    }
                    result[board[i][j] - '1'] = true;
                }
            }
            result = vector<bool>(9, false);
        }
		//this block of code is very elegant
        for (int block = 0; block < 9; ++block) {
            for (int i = block / 3 * 3; i < block / 3 * 3 + 3; ++i) {
                for (int j = block % 3 * 3; j < block % 3 * 3 + 3; ++j) {
                    if (board[i][j] != '.') {
                        if (result[board[i][j] - '1'] == true) {
                            return false;
                        }
                        result[board[i][j] - '1'] = true;
                    }
                }
            }
            result = vector<bool>(9, false);
        }
        return true;
    }
};
