class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int columnSize = rowSize == 0 ? 0 : matrix[0].size();
        return helper(matrix, target, 0, 0, rowSize - 1, columnSize - 1);
    }
private:
    bool helper(vector<vector<int>>& matrix, int target, int row1, int column1, int row2, int column2) {
        if (row1 > row2 || column1 > column2 || 
        target < matrix[row1][column1] || target > matrix[row2][column2]) {
            return false;
        }
        int middleRow = row1 + (row2 - row1) / 2;
        int middleColumn = column1 + (column2 - column1) / 2;
        int element = matrix[middleRow][middleColumn];
        if (element == target) {
            return true;
        } else if (element > target) {
            return helper(matrix, target, row1, column1, middleRow, middleColumn)
            || helper(matrix, target, row1, middleColumn + 1, middleRow, column2)
            || helper(matrix, target, middleRow + 1, column1, row2, middleColumn);
        } else {
            return helper(matrix, target, middleRow + 1, middleColumn + 1, row2, column2)
            || helper(matrix, target, row1, middleColumn + 1, middleRow, column2)
            || helper(matrix, target, middleRow + 1, column1, row2, middleColumn);
        }
    }
};