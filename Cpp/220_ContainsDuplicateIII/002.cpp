class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> treeSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                treeSet.erase(nums[i - 1 - k]);
            }
            auto iter = treeSet.lower_bound(nums[i] - t);
            //*iter - nums[i] <= t can avoid overflow
            if (iter != treeSet.end() && *iter - nums[i] <= t) {
                return true;
            }
            treeSet.insert(nums[i]);
        }
        return false;
    }
};