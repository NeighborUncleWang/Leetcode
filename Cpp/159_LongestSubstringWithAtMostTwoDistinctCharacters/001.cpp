class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> hashMap(256, 0);
        int maxLength = 0;
        int distinctNumber = 0;
        for (int start = 0, end = 0; end < s.size(); ++end) {
            //当char作为index时，因为opertator[]的input是size_type, 所以会被转化为unsigned类型
            if (hashMap[s[end]] == 0) {
                ++distinctNumber;
            }
            ++hashMap[s[end]];
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
