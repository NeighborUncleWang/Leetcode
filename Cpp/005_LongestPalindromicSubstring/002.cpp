class Solution {
public:
    string longestPalindrome(string s) {
        string::size_type n = s.size();
        int maxLength = 0;
        string result;
        for (int i = 0; i < n; ++i) {
            int left = i;
            int right = i;
            longestPalindromeHelper(s, left, right, maxLength, result);
            if (s[i] == s[i + 1]) {
                ++right;
                longestPalindromeHelper(s, left, right, maxLength, result);
            }
        }
        return result;
    }
private:
    void longestPalindromeHelper(string s, int left, int right, int& maxLength, string& result) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        auto substring = s.substr(left + 1, right - left - 1);
        if (substring.size() > maxLength) {
            maxLength = substring.size();
            result = substring;
        }
    }
};
