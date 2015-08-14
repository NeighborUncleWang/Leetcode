class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> treeSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                treeSet.erase(nums[i - k - 1]);
            }
            auto position = treeSet.lower_bound(nums[i] - t);
            //*position - nums[i] <= t can avoid overflow
            if (position != treeSet.end() && *position - nums[i] <= t) {
                return true;
            }
            treeSet.insert(nums[i]);
        }
        return false;
    }
};
