class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left = 0;
        int up = 0;
        int down = (int)matrix.size() - 1;
        int right = down >= 0 ? matrix[0].size() - 1 : -1;
        while (up <= down && left <= right) {
            //以前是每个for loop执行完都检查是否要break，然后外层是while(true)
            //现在只检查两次
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[up][j]);
            }
            ++up;
            //每次更新完就检查相应数值，比reference多写一个break语句
            //这样更好记忆一点
            if (up > down) break;
            for (int i = up; i <= down; ++i) {
                result.push_back(matrix[i][right]);
            }
            --right;
            if (left > right) break;
            for (int j = right; j >= left; --j) {
                result.push_back(matrix[down][j]);
            }
            --down;
            if (up > down) break;
            for (int i = down; i >= up; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
        }
        return result;
    }
};