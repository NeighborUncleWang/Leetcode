class Solution {
public:
    void solve(vector<vector<char>> &board) {
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
        for (auto& direction : directions) {
            int ii = i + direction.first;
            int jj = j + direction.second;
            //如果改成if (ii > 0 && ii < row - 1 && jj > 0 && jj < column - 1)
            //就能AC，因为有一个case是所有边界'O'像贪吃蛇一样连在一起的
            //那种写法可以把这个'O'的sequence分成多次visit
            //但是这道题还是不应该用DFS
            if (ii >= 0 && ii < row && jj >= 0 && jj < column) {
                floodFill(board, row, column, ii, jj, directions);
            }
        }
    }
};