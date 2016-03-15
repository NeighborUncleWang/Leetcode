class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int maxLength = 0;
        for (int num : nums) {
            if (hashMap.find(num) == hashMap.end()) {
                //left和right返回的值一定是单边的
                //也就是说如果right = 2,一定是代表num + 1, num + 2不可能是num, num + 1;
                //因为如果num + 1要扩展左边的sequence长度，那之前一定检查过num，发现num在hashMap里
                //然后给num + 1的left赋值了1，这才可能发生。
                int left = hashMap.find(num - 1) == hashMap.end() ? 0 : hashMap[num - 1];
                int right = hashMap.find(num + 1) == hashMap.end() ? 0 : hashMap[num + 1];
                int sum = left + right + 1;
                hashMap[num] = sum;
                maxLength = max(maxLength, sum);
                hashMap[num - left] = sum;
                hashMap[num + right] = sum;
            }
        }
        return maxLength;
    }
};