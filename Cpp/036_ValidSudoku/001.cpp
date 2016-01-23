class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used1(9, vector<bool>(9, false));
        vector<vector<bool>> used2(9, vector<bool>(9, false));
        vector<vector<bool>> used3(9, vector<bool>(9, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    int k = i / 3 * 3 + j / 3;
                    int num = board[i][j] - '1';
                    if (used1[i][num] || used2[j][num] || used3[k][num]) {
                        return false;
                    }
                    used1[i][num] = used2[j][num] = used3[k][num] = true;
                }
            }
        }
        return true;
    }
};