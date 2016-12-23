class Solution {
public:
    string shortestPalindrome(string s) {
        string r(s.rbegin(), s.rend());
        int n = s.size();
        for (int i = 0; i <= n; ++i) {
            if (r.substr(i) == s.substr(0, n - i)) {
                return r.substr(0, i) + s;
            }
        }
        return "";
    }
};