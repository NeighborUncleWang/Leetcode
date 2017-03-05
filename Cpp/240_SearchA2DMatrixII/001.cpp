class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if (rowSize == 0) {
            return false;
        }
        //起始位置必须选[0, col - 1]或者[row - 1, 0]
        //每次移动都能够排除当前行或者列剩下没检查的过的元素
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
