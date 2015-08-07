class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if (rowSize == 0) {
            return 0;
        }
        int columnSize = grid[0].size();
        int count = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (grid[i][j] == '#') {
                    grid[i][j] = '1';
                }
            }
        }
        return count;
    }
private:
    struct Node{
        int x;
        int y;
        Node(int x, int y) : x(x), y(y) {}
    };
    void bfs(vector<vector<char>>& grid, int row, int column) {
        queue<Node> nodesQueue;
        nodesQueue.push(Node(row, column));
        grid[row][column] = '#';
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            auto xPosition = node.x;
            auto yPosition = node.y;
            //must check four directions instead just check(x, y + 1) and (x + 1, y)
            //because that will not pass the {"111", "010", "111"} case
            visit(grid, nodesQueue, xPosition, yPosition + 1);
            visit(grid, nodesQueue, xPosition + 1, yPosition);
            visit(grid, nodesQueue, xPosition - 1, yPosition);
            visit(grid, nodesQueue, xPosition, yPosition - 1);
        }
    }
    void visit(vector<vector<char>>& grid, queue<Node>& nodesQueue, int row, int column) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() 
        || grid[row][column] != '1') {
            return;
        }
        grid[row][column] = '#';
        nodesQueue.push(Node(row, column));
    }
};
