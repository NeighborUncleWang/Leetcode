class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int column = row == 0 ? 0 : board[0].size();
        vector<pair<int, int>> directions{{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
        for (int i = 0; i < row; ++i) {
            floodFill(board, row, column, i, 0, directions);
            floodFill(board, row, column, i, column - 1, directions);
        }
        for (int j = 0; j < column; ++j) {
            floodFill(board, row, column, 0, j, directions);
            floodFill(board, row, column, row - 1, j, directions);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void floodFill(vector<vector<char>>& board, int row, int column, int i, int j,
                   vector<pair<int, int>>& directions) {
        //本来按常理这个条件应该在调用floodFill之前检查，
        //如果board[i][j] == 'O',才调用floodFill
        //但是写在floodFill里可以减少void slove()函数里检查的次数
        //所以这题就写在floodFill里了，wikipedia上floodfill也是这样的写法
        if (board[i][j] != 'O') return;
        board[i][j] = '#';
        queue<pair<int, int>> nodesQueue;
        nodesQueue.emplace(i, j);
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            for (auto &direction : directions) {
                int ii = node.first + direction.first;
                int jj = node.second + direction.second;
                if (ii >= 0 && ii < row && jj >= 0 && jj < column && board[ii][jj] == 'O') {
                    nodesQueue.emplace(ii, jj);
                    board[ii][jj] = '#';
                }
            }
        }
    }
};