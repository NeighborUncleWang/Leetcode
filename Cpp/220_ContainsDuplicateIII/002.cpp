class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //这题nums有重复也不影响正确结果，所以没关系
        set<long long> treeSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                treeSet.erase(nums[i - 1 - k]);
            }
            //set也要用long long类型，否则lower_bound的时候还是会把输入转换成int
            auto iter = treeSet.lower_bound((long long)nums[i] - t);
            //*iter - nums[i] <= t can avoid overflow
            if (iter != treeSet.end() && *iter - (long long)nums[i] <= t) {
                return true;
            }
            treeSet.insert(nums[i]);
        }
        return false;
    }
};