class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int added = 0;
        int i = 0;
        //这里while条件必须是miss <= n而不是 i < nums.size()
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++added;
            }
        }
        return added;
    }
};