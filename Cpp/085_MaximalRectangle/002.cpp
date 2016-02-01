class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int column = row == 0 ? 0 : matrix[0].size();
        vector<int> height(column, 0);
        //The value of left & right means the boundaries of the rectangle 
        //which contains the current point with a height of current height.
        vector<int> left(column, 0);
        vector<int> right(column, column - 1);
        int maxArea = 0;
        for (int i = 0; i < row; ++i) {
            int currentLeft = 0;
            int currentRight = column - 1;
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                    left[j] = max(left[j], currentLeft);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    currentLeft = j + 1;
                }
            }
            for (int j = column - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currentRight);
                } else {
                    right[j] = column - 1;
                    currentRight = j - 1;
                }
            }
            for (int j = 0; j < column; ++j) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j] + 1));
            }
        }
        return maxArea;
    }
};