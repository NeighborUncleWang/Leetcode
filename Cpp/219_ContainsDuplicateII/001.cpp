class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                hashSet.erase(nums[i - k - 1]);
            }
            if (hashSet.insert(nums[i]).second == false) {
                return true;
            }
        }
        return false;
    }
};