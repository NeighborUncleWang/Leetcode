class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int columnSize = rowSize == 0 ? 0 : grid[0].size();
        vector<int> rows(rowSize, 0);
        vector<int> columns(columnSize, 0);
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                rows[i] += grid[i][j];
                columns[j] += grid[i][j];
            }
        }
        return getDistance1D(rows) + getDistance1D(columns);
    }
private:
    int getDistance1D(vector<int>& position) {
        int i = -1;
        int j = position.size();
        int left = 0;
        int right = 0;
        int distance = 0;
        while (i < j) {
            if (left < right) {
                distance += left;
                left += position[++i];
            } else {
                distance += right;
                right += position[--j];
            }
        }
        return distance;
    }
};