class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> hashMap(256, 0);
        int maxLength = 0;
        int distinctNumber = 0;
        for (int start = 0, end = 0; end < s.size(); ++end) {
            //当char作为index时，因为opertator[]的input是size_type, 所以会被转化为unsigned类型
            ++hashMap[s[end]];
            if (hashMap[s[end]] == 1) {
                ++distinctNumber;
            }
            //其实可以把下面的loop写在if (hashMap[s[end]] == 1)里面
            //因为只有发现新的distinct number的时候才需要检查是否超过两个distinct number
            while (distinctNumber > 2) {
                --hashMap[s[start]];
                if (hashMap[s[start]] == 0) {
                    --distinctNumber;
                }
                ++start;
            }
            maxLength = max(maxLength, end - start + 1);
        } 
        return maxLength;
    }
};