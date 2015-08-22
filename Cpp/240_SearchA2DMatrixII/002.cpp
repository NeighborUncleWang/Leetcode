class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return false;
        }
        int columnSize = matrix[0].size();
        return helper(matrix, 0, columnSize - 1, 0, rowSize - 1, target);
    }
private:
    bool helper(vector<vector<int>>& matrix, int left, int right, int up, int down, int target) {
        if (left > right || up > down ||
        target < matrix[up][left] || target > matrix[down][right]) {
            return false;
        }
        int centralRow = up + (down - up) / 2;
        int centralColumn = left + (right - left) / 2;
        if (target == matrix[centralRow][centralColumn]) {
            return true;
        } else if (target > matrix[centralRow][centralColumn]) {
            return helper(matrix, centralColumn + 1, right, up, centralRow, target)
            || helper(matrix, left, centralColumn, centralRow + 1, down, target)
            || helper(matrix, centralColumn + 1, right, centralRow + 1, down, target);
        } else {
            return helper(matrix, left, centralColumn, up, centralRow, target)
            || helper(matrix, centralColumn + 1, right, up, centralRow, target)
            || helper(matrix, left, right, centralRow + 1, down, target);
        }
    }
};
