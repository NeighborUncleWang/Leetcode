class Solution {
public:
    string longestPalindrome(string s) {
        string::size_type n = s.size();
        int maxLength = 0;
        string result;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int left = i / 2;
            int right = i / 2;
            if (i % 2) {
                ++right;
            }
            auto substring = longestPalindromeHelper(s, left, right);
            if (substring.size() > maxLength) {
                maxLength = substring.size();
                result = substring;
            }
        }
        return result;
    }
private:
    string longestPalindromeHelper(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
