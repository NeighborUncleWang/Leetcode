class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int num : nums) {
            //这里两个if都必须用<=而不是<
            //否则num == min1时min2会被update
            //[1,1,1]case会出错
            if (num <= min1) {
                min1 = num;
            } else if (num <= min2) {
                min2 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};