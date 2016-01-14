class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        for (int num : nums) {
            if (++hashMap[num] > n / 2) {
                return num;
            }
        }
    }
};