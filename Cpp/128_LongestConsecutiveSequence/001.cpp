class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (auto i : nums) {
            hashSet.insert(i);
        }
        int length, maxLength = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = nums[i];
            length = 0;
            auto it = hashSet.find(temp);
            while (hashSet.end() != it) {
                ++length;
                hashSet.erase(it);
                ++temp;
                it = hashSet.find(temp);
            }
            temp = nums[i] - 1;
            it = hashSet.find(temp);
            while (hashSet.end() != it) {
                ++length;
                hashSet.erase(it);
                --temp;
                it = hashSet.find(temp);
            }
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }
};
