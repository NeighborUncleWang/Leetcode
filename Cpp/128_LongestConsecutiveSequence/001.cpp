class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxLength = 0;
        for (int num : hashSet) {
            if (hashSet.find(num - 1) == hashSet.end()) {
                int end = num;
                while (hashSet.find(end) != hashSet.end()) {
                    ++end;
                }
                maxLength = max(maxLength, end - num);
            }
        }
        return maxLength;
    }
};