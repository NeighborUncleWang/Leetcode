class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rowSize = rooms.size();
        int columnSize = rowSize == 0 ? 0 : rooms[0].size();
        vector<vector<int>> minDistance(rowSize, vector<int>(columnSize, INT_MAX));
        vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> nodesQueue;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (rooms[i][j] == 0) {
                    nodesQueue.emplace(i, j);
                }
            }
        }
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            for (auto direction : directions) {
                int newX = node.first + direction.first;
                int newY = node.second + direction.second;
                if (newX >= 0 && newX < rowSize && newY >= 0 && newY < columnSize
                && rooms[node.first][node.second] + 1 < rooms[newX][newY]) {
                    rooms[newX][newY] = rooms[node.first][node.second] + 1;
                    nodesQueue.emplace(newX, newY);
                }
            }
        }
    }
};