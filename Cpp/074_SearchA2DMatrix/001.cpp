class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int columnSize = rowSize == 0 ? 0 : matrix[0].size();
        long long low = 0;
        long long high = rowSize * columnSize - 1;
        while (low <= high) {
            long long middle = low + (high - low) / 2;
            int row = middle / columnSize;
            int column = middle % columnSize;
            if (matrix[row][column] == target) {
                return true;
            } else if (matrix[row][column] < target) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return false;
    }
};