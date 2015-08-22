class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return false;
        }
        for (int i = rowSize - 1, j = 0; i >= 0 && j < matrix[0].size(); ) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
};
