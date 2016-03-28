class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int currentSum = 0;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (currentSum == k) {
                maxLength = i + 1;
            } else if (hashMap.find(currentSum - k) != hashMap.end()) {
                maxLength = max(maxLength, i - hashMap[currentSum - k]);
            }
            //如果有多个index都能sums up to currentSum
            //要保留最小的index
            //所以这里要先检查hashMap里是否有这个key
            //有的话就不要update
            if (hashMap.find(currentSum) == hashMap.end()) {
                hashMap[currentSum] = i;
            }
        }
        return maxLength;
    }
};