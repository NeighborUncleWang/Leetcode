class Solution {
public:
    bool canJump(vector<int>& nums) {
        //my code can stop early once currentLast >= size - 1
        //and when nums is empty, it can return true
        int size = nums.size();
        int currentLast = 0;
        for (int i = 0; i < size && i <= currentLast; ++i) {
            if (currentLast >= size - 1) return true;
            currentLast = max(currentLast, i + nums[i]);
        }
        return currentLast >= size - 1;
    }
};