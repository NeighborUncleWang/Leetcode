class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int currentMax = 0;
        int nextMax = 0;
        int i = 0;
        int level = 0;
        while (i <= currentMax) {
            for (; i <= currentMax; ++i) {
                nextMax = max(i + nums[i], nextMax);
                if (nextMax + 1 >= size) {
                    return level + 1;
                }
            }
            //we can add if (currentMax == nextMax) return INT_MAX
            //if there is no way to jump to the last index
            //however, this problem guarantees there is a way
            currentMax = nextMax;
            ++level;
        }
    }
};