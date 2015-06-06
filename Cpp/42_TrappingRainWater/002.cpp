class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int level = 0, temp = 0, sum = 0, block = 0;
        while (left <= right) {
            temp = min(height[left], height[right]);
            if (temp > level) {
                sum += (temp - level) * (right - left + 1);
                level = temp;
            }
            block += temp;
            height[left] < height[right] ? ++left : --right;
        }
        return sum - block;
    }
};
