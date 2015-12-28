class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int columnSize = rowSize == 0 ? 0 : grid[0].size();
        vector<vector<int>> reachable(rowSize, vector<int>(columnSize, 0));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> distances(rowSize, vector<int>(columnSize, 0));
        int building = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (1 == grid[i][j]) {
                    queue<pair<int, int>> nodesQueue;
                    nodesQueue.emplace(i, j);
                    int currentLevel = 1;
                    int nextLevel = 0;
                    int distance = 1;
                    while (!nodesQueue.empty()) {
                        auto node = nodesQueue.front();
                        nodesQueue.pop();
                        --currentLevel;
                        for (auto direction : directions) {
                            int newX = node.first + direction.first;
                            int newY = node.second + direction.second;
                            //we don't need the visted[rowSize][columnSize] matrix
                            //since when we test reachable[newX][newY] == building
                            //this guarantees (newX, newY) is unvisited
                            if (newX >= 0 && newX < rowSize && newY >= 0 && newY < columnSize
                                && reachable[newX][newY] == building && grid[newX][newY] == 0) {
                                ++nextLevel;
                                nodesQueue.emplace(newX, newY);
                                ++reachable[newX][newY];
                                distances[newX][newY] += distance;
                            }
                        }
                        if (currentLevel == 0) {
                            currentLevel = nextLevel;
                            nextLevel = 0;
                            ++distance;
                        }
                    }
                    ++building;
                }
            }
        }
        int minDistance = INT_MAX;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (grid[i][j] == 0 && reachable[i][j] == building) {
                    minDistance = min(minDistance, distances[i][j]);
                }
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};