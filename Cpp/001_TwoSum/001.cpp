class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashMap.find(target - nums[i]);
            if (it != hashMap.end()) {
                return vector<int>{it->second, i + 1};
            }
            hashMap[nums[i]] = i + 1;// if I change this part to if (...) {} else {hashMap[nums[i]]} the speed will change from 20ms to 24ms
        }
    }
};
