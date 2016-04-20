class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k <= 0) return 0;
        int distinct = 0;
        vector<int> hashMap(256, 0);
        int maxLength = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (++hashMap[s[right]] == 1) {
                ++distinct;
                while (distinct > k) {
                    if (--hashMap[s[left++]] == 0) {
                        --distinct;
                    }
                }
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};