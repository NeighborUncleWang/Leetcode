class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int maxLength = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (++count[s[right]] == 2) {
                while (--count[s[left++]] != 1) {};
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};