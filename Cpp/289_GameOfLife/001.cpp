class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int columnSize = rowSize ? board[0].size() : 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                //因为是计算neighbors的活着的数目，所以要除掉当前点
                int lives = -(board[i][j] & 1);
                for (int I = max(0, i - 1); I < min(i + 2, rowSize); ++I) {
                    for (int J = max(0, j - 1); J < min(j + 2, columnSize); ++J) {
                        //must be board[I][J] & 1 instead of board[I][J]
                        //since some board[I][J] may already be modified
                        lives += board[I][J] & 1;
                    }
                }
                if (board[i][j] & 1 && lives == 2 || lives == 3) board[i][j] |= 2;
                if (board[i][j] & 1 == 0 && lives == 3) board[i][j] |= 2;
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};