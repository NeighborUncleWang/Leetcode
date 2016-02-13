class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        //sums[i][j] sotres sum from matrix[0][0] to matrix[i - 1][j - 1]
        //so sums[0][j] and sums[i][0] are all 0s.
        int rowSize = matrix.size();
        int columnSize = rowSize == 0 ? : matrix[0].size();
        sums = vector<vector<int>>(rowSize + 1, vector<int>(columnSize + 1, 0));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] + sums[row1][col1] - sums[row1][col2 + 1] - sums[row2 + 1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);