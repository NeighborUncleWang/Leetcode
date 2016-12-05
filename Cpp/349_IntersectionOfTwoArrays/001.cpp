class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums(nums1.begin(), nums1.end());
        vector<int> result;
        for (int num : nums2) {
            if (nums.erase(num)) {
                result.push_back(num);
            }
        }
        return result;
    }
};