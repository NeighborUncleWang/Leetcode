class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int columnSize = rowSize ? board[0].size() : 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                int count = -board[i][j];
                for (int I = max(0, i - 1); I < min(i + 2, rowSize); ++I) {
                    for (int J = max(0, j - 1); J < min(j + 2, columnSize); ++J) {
                        //must be board[I][J] & 1 instead of board[I][J]
                        //since some board[I][J] may already be modified
                        count += board[I][J] & 1;
                    }
                }
                if (count == 3 || count + board[i][j] == 3) board[i][j] |= 2;
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};