class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = row ? matrix[0].size() : 0;
        vector<int> res(row * col, 0);
        for (int i = 0, j = 0, direction = 1, k = 0; k < row * col; ++k) {
            res[k] = matrix[i][j];
            i -= direction;
            j += direction;
            //j >= col 和 i >= row必须写在i < 0 和 j < 0前面
            //比如题目给的例子例当路径从右上角越界的时候，必须要判断上越过右边界才能继续修正回来
            //如果判断成越过上边界，那么经过修正只有i = 0, j还是越界
            if (j >= col) {
                j = col - 1;
                i += 2;
                direction = -direction;
            } else if (i >= row) {
                i = row - 1;
                j += 2;
                direction = -direction;
            } else if (i < 0) {
                i = 0;
                direction = -direction;
            } else if (j < 0) {
                j = 0;
                direction = -direction;
            }
        }
        return res;
    }
};