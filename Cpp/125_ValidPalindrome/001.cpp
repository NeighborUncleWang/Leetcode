class Solution {
public:
    bool isPalindrome(string s) {
        //也可以直接写transform(s.begin(), s.end(), s.begin(), ::tolower);
        //tolower前面一定要加::,否则编译通不过，不知道为什么
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