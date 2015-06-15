class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (0 == matrix.size()) {
            return 0;
        }
        vector<int> height(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j <matrix[0].size(); ++j) {
                if ('1' == matrix[i][j]) {
                    height[j] = height[j] + 1;
                } else {
                    height[j] = 0;
                }
            }
            int area = findMaxRectangleHistogram(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int findMaxRectangleHistogram(vector<int>& height) {
        stack<int> st;
        height.push_back(0);
        int i = 0, area, maxArea = 0, topHeight;
        while (i < height.size()) {
            if (st.empty() || height[st.top()] <= height[i]) {
                st.push(i);
                ++i;
            } else {
                topHeight = height[st.top()];
                st.pop();
                area = topHeight * (st.empty() ? i : i - st.top() - 1);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};
