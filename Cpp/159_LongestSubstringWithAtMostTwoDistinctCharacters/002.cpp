class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0;
        int end = 0;
        unordered_map<char, int> hashMap;
        int maxLength = 0;
        while (end < s.size()) {
            ++hashMap[s[end]];
            while (hashMap.size() > 2) {
                --hashMap[s[start]];
                if (hashMap[s[start]] == 0) {
                    hashMap.erase(s[start]);
                }
                ++start;
            }
            maxLength = max(maxLength, end - start + 1);
            ++end;
        }
        return maxLength;
    }
};
