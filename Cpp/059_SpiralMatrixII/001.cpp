class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int up = 0, left = 0, down = n - 1, right = n - 1;
        int j = 0;
        while (true) {
            for (int i = left; i <= right; ++i) {
                result[up][i] = ++j;
            }
            ++up;
            if (up > down) {
                break;
            }
            for (int i = up; i <= down; ++i) {
                result[i][right] = ++j;
            }
            --right;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                result[down][i] = ++j;
            }
            --down;
            if (down < up) {
                break;
            }
            for (int i = down; i >= up; --i) {
                result[i][left] = ++j;
            }
            ++left;
            if (left > right) {
                break;
            }
        }
        return result;
    }
};
