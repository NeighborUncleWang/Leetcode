class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k, n);
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};