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
                    queue<pair<int, int>> nodesQueue;
                    nodesQueue.emplace(i, j);
                    int distance = 1;
                    minDistance = INT_MAX;
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
                                    minDistance = min(minDistance, distances[ii][jj]);
                                }
                            }
                        }
                        ++distance;
                    }
                    ++building;
                }
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};