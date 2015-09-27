class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        if (left >= right) {
            return 0;
        }
        int sum_water = 0;  
        while(left < right) {
            if (height[left] < height[right]) {
                int min_height = height[left];
                ++left;
                while (left < right && height[left] < min_height) {
                    sum_water += min_height - height[left];
                    ++left;
                }
            } else {
                int min_height = height[right];
                --right;
                while (left < right && height[right] < min_height) {
                    sum_water += min_height - height[right];
                    --right;
                }
            }
        }
        return sum_water;
    }
};
