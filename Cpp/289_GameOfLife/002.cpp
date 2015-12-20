class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //0 dead to dead
        //1 live to live
        //2 live to dead
        //3 dead to live
        vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}
        };
        int rowSize = board.size();
        int columnSize = rowSize ? board[0].size() : 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                int count = 0;
                for (vector<int>& direction : directions) {
                    int newX = i + direction[0];
                    int newY = j + direction[1];
                    if (newX >= 0 && newX < rowSize && newY >= 0 && newY < columnSize) {
                        if (board[newX][newY] == 1 || board[newX][newY] == 2) ++count;
                    }
                }
                if (board[i][j] == 1) {
                    board[i][j] += count == 3 || count == 2 ? 0 : 1;
                } else {
                    board[i][j] += count == 3 ? 3 : 0; 
                }
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};