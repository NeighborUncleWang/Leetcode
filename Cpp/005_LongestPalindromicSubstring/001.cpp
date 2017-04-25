class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            int len1 = helper(s, i, i);
            int len2 = helper(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = start + len;
            }
        }
        return s.substr(start, end - start);
    }
private:
    //or we can return pair<int, int> to store both length and
    //start index to make life easier
    int helper(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            ++right;
            --left;
        }
        return right - left - 1;
    }
};