class Solution {
public:
    int trap(vector<int> &height) {
        int maxLeft = 0;
        int maxRight = 0;
        int result = 0;
        int left = 0;
        int right = (int) height.size() - 1;
        while (left < right) {
            if (height[left] <= height[right]) {
                //其实下面if-else可以写成
                //maxLeft = max(height[left], maxLeft);
                //result += maxLeft - hegiht[left];
                //因为如果maxLeft被更新了,那maxLeft - height[left]一定为0
                //现在这样写算法稍微好理解一点
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    result += maxLeft - height[left];
                }
                ++left;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    result += maxRight - height[right];
                }
                --right;
            }
        }
        return result;
    }
};