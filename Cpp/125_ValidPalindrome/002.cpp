class Solution {
public:
    bool isPalindrome(string s) {
        for (int left = 0, right = (int)s.size() - 1; left < right; ++left, --right) {
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (toupper(s[left]) != toupper(s[right])) return false;
        }
        return true;
    }
};