class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> position(256, -1);
        int maxLength = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (position[s[right]] >= left) {
                left = position[s[right]] + 1;
            }
            position[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};