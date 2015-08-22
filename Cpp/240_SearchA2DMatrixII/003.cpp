class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return false;
        }
        int columnSize = matrix[0].size();
        return helper(matrix, target, 0, rowSize - 1, 0, columnSize - 1);
    }
private:
    bool helper(vector<vector<int>>& matrix, int target, int up, int down, int left, int right) {
        if (up > down || left > right || target < matrix[up][left] || target > matrix[down][right]) {
            return false;
        }
        int midColumn = left + (right - left) / 2;
        int upRow = up;
        int downRow = down;
        //binary search
        while (upRow <= downRow) {
            int midRow = upRow + (downRow - upRow) / 2;
            if (target == matrix[midRow][midColumn]) {
                return true;
            } else if (target < matrix[midRow][midColumn]) {
                downRow = midRow - 1;
            } else {
                upRow = midRow + 1;
            }
        }
        return helper(matrix, target, upRow, down, left, midColumn - 1)
        || helper(matrix, target, up, downRow, midColumn + 1, right);
    }
};
