class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int column = row ? board[0].size() : 0;
        int count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') && 
                (j == 0 || board[i][j - 1] != 'X')) {
                    ++count;
                }
            }
        }
        return count;
    }
};