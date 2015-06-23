class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> result;
        while (true) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[up][i]);
            }
            ++up;
            if (up > down) {
                break;
            }
            for (int i = up; i <= down; ++i) {
                result.push_back(matrix[i][right]);
            }
            --right;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[down][i]);
            }
            --down;
            if (down < up) {
                break;
            }
            for (int i = down; i>= up; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
            if (left > right) {
                break;
            }
        }
        return result;
    }
};
