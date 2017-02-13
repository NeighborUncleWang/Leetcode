class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> indices;
        int i = 0;
        int maxArea = 0;
        while (i < height.size()) {
            if (indices.empty() || height[indices.top()] <= height[i]) {
                indices.push(i++);
            } else {
                int t = indices.top();
                indices.pop();
                maxArea = max(maxArea, height[t] * (indices.empty() ? i : i - indices.top() - 1));
            }
        }
        return maxArea;
    }
};
