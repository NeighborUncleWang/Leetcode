class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int column = row == 0? 0 : matrix[0].size();
        vector<int> heights(column + 1, 0);
        int maxArea = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            stack<int> indices;
            for (int j = 0; j < column + 1; ++j) {
                while (!indices.empty() && heights[indices.top()] > heights[j]) {
                    int height = heights[indices.top()];
                    indices.pop();
                    maxArea = max(maxArea, height * (indices.empty() ? j : j - indices.top() - 1));
                }
                indices.push(j);
            }
        }
        return maxArea;
    }
};