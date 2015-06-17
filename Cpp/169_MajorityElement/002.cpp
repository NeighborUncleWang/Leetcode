class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashMap.find(nums[i]);
            if (hashMap.end() == it) {
                hashMap[nums[i]] = 1;
                if (1 > nums.size() / 2) {
                    return nums[i];
                }
            } else {
                ++it->second;
                if (it->second > nums.size() / 2) {
                    return it->first;
                }
            }
        }
    }
};
