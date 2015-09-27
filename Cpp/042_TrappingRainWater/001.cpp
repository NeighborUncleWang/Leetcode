class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        if (height_size < 3) {
            return 0;
        }
        vector<int> container(height_size, 0);
        int left_max = 0;
        //这里left_max和right_max都不包含当前height[i]的值
        //都是至少+1后者-1之后的最大高度
        for (int i = 0; i < height_size; ++i) {
            container[i] = left_max;
            left_max = max(left_max, height[i]);
        }
        int sum_water = 0;
        int right_max = 0;
        for (int i = height_size - 1; i >= 0; --i) {
            container[i] = min(container[i], right_max);
            right_max = max(right_max, height[i]);
            sum_water += max(container[i] - height[i], 0);
        }
        return sum_water;
    }
};
