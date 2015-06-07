class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() * matrix[0].size() - 1;
        int median, row, column;
        while (low <= high) {
            median = (low + high) / 2;
            row = median / matrix[0].size();
            column = median % matrix[0].size();
            if (matrix[row][column] == target) {
                return true;
            } else if (matrix[row][column] < target) {
                low = median + 1;
            } else {
                high = median - 1;
            }
        }
        return false;
    }
};
