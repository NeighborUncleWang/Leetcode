class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        bool col0 = false;
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
            }
            for (int j = 1; j < column; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            //这里顺序不能换，必须最后对matrix[i][0]赋值0
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};