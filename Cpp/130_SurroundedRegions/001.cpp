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
    struct Node{
        int x = 0;
        int y = 0;
        Node(int _x, int _y) : x(_x), y(_y) {}
    };
    void floodFill(vector<vector<char>>& board, int i, int j, char currentChar, char newChar) {
        if (board[i][j] != currentChar) {
            return;
        }
        board[i][j] = newChar;
        queue<Node> nodesQueue;
        int rowNumber = board.size();
        int columnNumber = board[0].size();
        Node root(i, j);
        nodesQueue.push(root);
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            int row = node.x;
            int column = node.y;
            if (column > 0 && board[row][column - 1] == currentChar) {
                nodesQueue.push(Node(row, column - 1));
                //要在把node放到queue中之前改成newChar，而不是每次从queue中取出再改成newChar
                //这样可以避免一个node被重复加入到queue中
                board[row][column - 1] = newChar;
            }
            if (row < rowNumber - 1 && board[row + 1][column] == currentChar) {
                nodesQueue.push(Node(row + 1, column));
                board[row + 1][column] = newChar;
            }
            if (column < columnNumber - 1 && board[row][column + 1] == currentChar) {
                nodesQueue.push(Node(row, column + 1));
                board[row][column + 1] = newChar;
            }
            if (row > 0 && board[row - 1][column] == currentChar) {
                nodesQueue.push(Node(row - 1, column));
                board[row - 1][column] = newChar;
            }
        }
    }
};
