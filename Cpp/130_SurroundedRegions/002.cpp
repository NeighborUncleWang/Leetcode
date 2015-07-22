class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < n; ++i) {
            floodFill(board, 0, i, 'O', '#');
            floodFill(board, m - 1, i, 'O', '#');
        }
        for (int i = 0; i < m; ++i) {
            floodFill(board, i, 0, 'O', '#');
            floodFill(board, i, n - 1, 'O', '#');
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void floodFill(vector<vector<char>>& board, int i, int j, char currentChar, char newChar) {
        if (board[i][j] != currentChar) {
            return;
        }
        board[i][j] = newChar;
        queue<int> nodesQueue;
        int rowNumber = board.size();
        int columnNumber = board[0].size();
        //actually this may cause overflow, a more cautious way is to define a struct node{int x; int y;};
        nodesQueue.push(i * columnNumber + j);
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            int row = node / columnNumber;
            int column = node % columnNumber;
            int code = row * columnNumber + column;
            if (column > 0 && board[row][column - 1] == currentChar) {
                nodesQueue.push(code - 1);
                board[row][column - 1] = newChar;
            }
            if (row < rowNumber - 1 && board[row + 1][column] == currentChar) {
                nodesQueue.push(code + columnNumber);
                board[row + 1][column] = newChar;
            }
            if (column < columnNumber - 1 && board[row][column + 1] == currentChar) {
                nodesQueue.push(code + 1);
                board[row][column + 1] = newChar;
            }
            if (row > 0 && board[row - 1][column] == currentChar) {
                nodesQueue.push(code - columnNumber);
                board[row - 1][column] = newChar;
            }
        }
    }
};
