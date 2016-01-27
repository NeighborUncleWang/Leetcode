class Solution {
public:
    int rob(vector<int>& nums) {
        int robbed = 0;
        int notRobbed = 0;
        for (int num : nums) {
            //use temp to store previous robbed value
            int temp = robbed;
            robbed = notRobbed + num;
            notRobbed = max(temp, notRobbed);
        }
        return max(robbed, notRobbed);
    }
};