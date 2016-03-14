class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        bool col0 = false;
        bool row0 = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row0 = true;
                    if (j == 0) col0 = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < column; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
            //其实if (col0)可以写在这个loop里
            //但是row0不行
            if (col0) matrix[i][0] = 0;
        }
        //matrix[0][0]不需要根据row0和col0来设置，之前已经设置好了
        if (row0) {
            for (int j = 1; j < column; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};