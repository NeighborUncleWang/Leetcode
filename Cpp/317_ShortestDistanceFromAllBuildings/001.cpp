class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = row == 0 ? 0 : grid[0].size();
        vector<vector<int>> distances(row, vector<int>(column, 0));
        vector<vector<int>> reachability(row, vector<int>(column, 0));
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int building = 0;
        int minDistance = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    //其实不用每次碰到grid[i][j] == 1都重新声明一个queue
                    //可以在两个for loop最外面声明一个queue重复使用
                    //因为每次bfs结束queue都会变成empty
                    queue<pair<int, int>> nodesQueue;
                    nodesQueue.emplace(i, j);
                    int distance = 1;
                    while (!nodesQueue.empty()) {
                        int size = nodesQueue.size();
                        for (int k = 0; k < size; ++k) {
                            auto node = nodesQueue.front();
                            nodesQueue.pop();
                            for (auto& direction : directions) {
                                int ii = node.first + direction.first;
                                int jj = node.second + direction.second;
                                //we don't need the visted[rowSize][columnSize] matrix
                                //since when we test reachability[ii][jj] == building
                                //this guarantees (ii, jj) is unvisited
                                if (ii >= 0 && ii < row && jj >= 0 && jj < column 
                                && reachability[ii][jj] == building && grid[ii][jj] == 0) {
                                    nodesQueue.emplace(ii, jj);
                                    ++reachability[ii][jj];
                                    distances[ii][jj] += distance;
                                }
                            }
                        }
                        ++distance;
                    }
                    ++building;
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (reachability[i][j] == building) {
                    minDistance = min(minDistance, distances[i][j]);
                }
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};