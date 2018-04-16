class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        int res = 0;
        for (int i = 0; i < row - 1; ++i) {
            for (int j = i + 1; j < row; ++j) {
                int count = 0;
                for (int k = 0; k < col; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) {
                        res += count;
                        ++count;
                    }
                }
            }
        }
        return res;
    }
};
