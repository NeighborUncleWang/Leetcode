class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxGlobal = nums[0], minLocal = nums[0];
        int maxLocal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int maxCopy = maxLocal;
            maxLocal = max(minLocal * nums[i], max(maxLocal * nums[i], nums[i]));
            minLocal = min(maxCopy * nums[i], min(minLocal * nums[i], nums[i]));
            maxGlobal = max(maxGlobal, maxLocal);
        }
        return maxGlobal;
    }
};
