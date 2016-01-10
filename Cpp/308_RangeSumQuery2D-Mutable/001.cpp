class NumMatrix {
private:
    vector<vector<int>> matrix;
    int rowSize;
    int columnSize;
    vector<vector<int>> BIT;
    void updateBIT(int row, int col, int diff) {
        ++row;
        ++col;
        while (row <= rowSize) {
            int newCol = col;
            while (newCol <= columnSize) {
                BIT[row][newCol] += diff;
                newCol += (newCol & -newCol);
            }
            row += (row & -row);
        }
    }
    int getSumRegion(int row, int col) {
        int sum = 0;
        ++row;
        ++col;
        while (row > 0) {
            int newCol = col;
            while (newCol > 0) {
                sum += BIT[row][newCol];
                newCol -= (newCol & -newCol);
            }
            row -= (row & -row);
        }
        return sum;
    }
public:
    NumMatrix(vector<vector<int>> &matrix) : matrix(matrix) {
        rowSize = matrix.size();
        columnSize = rowSize == 0 ? 0 : matrix[0].size();
        BIT = vector<vector<int>>(rowSize + 1, vector<int>(columnSize + 1, 0));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                updateBIT(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        updateBIT(row, col, diff);
        matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSumRegion(row2, col2) - getSumRegion(row2, col1 - 1)
        - getSumRegion(row1 - 1, col2) + getSumRegion(row1 - 1, col1 - 1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);