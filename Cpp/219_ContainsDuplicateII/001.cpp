class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(nums[i]) && (i - hashMap[nums[i]] <= k)) {
                return true;
            }
            hashMap[nums[i]] = i;
        }
        return false;
    }
};
