class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redIndex = -1;
        int blueIndex = nums.size();
        int whiteIndex = 0;
        //the loop invariant:
        //at the beginning of each iteration of the loop:
        //nums[0...redIndex] are all red(0)
        //nums[redIndex...whiteIndex - 1] are all white(1)
        //nums[blueIndex...n - 1] are all blue
        //elements in nums[whiteIndex...blueIndex - 1] are elements waiting to be partitioned
        //this idea comes from CLRS's parition function for quick-sort
        //whiteIndex is comparing to variable j in that function
        //redIndex is comparing to variable i in that function
        while (whiteIndex < blueIndex) {
            if (nums[whiteIndex] == 0) {
                swap(nums[++redIndex], nums[whiteIndex]);
                ++whiteIndex;
            } else if (nums[whiteIndex] == 2) {
                swap(nums[--blueIndex], nums[whiteIndex]);
            } else {
                ++whiteIndex;
            }
        }
    }
};