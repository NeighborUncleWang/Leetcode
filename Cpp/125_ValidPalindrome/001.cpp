class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](char ch) { return tolower(ch); });
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};