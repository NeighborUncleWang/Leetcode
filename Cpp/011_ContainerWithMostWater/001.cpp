class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, area;
        int low = 0, high = height.size() - 1;
        while (low != high) {
            area = min(height[low], height[high]) * (high - low);
            maxArea = max(maxArea, area);
            if (height[low] < height[high]) {
                ++low;
            } else {
                --high;
            }
        }
        return maxArea;
    }
};
