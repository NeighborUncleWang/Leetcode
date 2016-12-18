class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        int column = row ? heightMap[0].size() : 0;
        if (row < 2 || column < 2) return 0;
        auto comp = [&heightMap](pair<int, int> a, pair<int, int> b) {
            return heightMap[a.first][a.second] > heightMap[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        for (int i = 0; i < row; ++i) {
            heap.emplace(i, 0);
            heap.emplace(i, column - 1);
            visited[i][0] = true;
            visited[i][column - 1] = true;
        }
        for (int j = 1; j < column - 1; ++j) {
            heap.emplace(0, j);
            heap.emplace(row - 1, j);
            visited[0][j] = true;
            visited[row - 1][j] = true;
        }
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int result = 0;
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            for (auto direction : directions) {
                int ii = top.first + direction.first;
                int jj = top.second + direction.second;
                if (ii >= 0 && ii < row && jj >= 0 && jj < column && !visited[ii][jj]) {
                    result += max(0, heightMap[top.first][top.second] - heightMap[ii][jj]);
                    heightMap[ii][jj] = max(heightMap[ii][jj], heightMap[top.first][top.second]);
                    heap.emplace(ii, jj);
                    visited[ii][jj] = true;
                }
            }
        }
        return result;
    }
};