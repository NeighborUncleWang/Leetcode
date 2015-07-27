class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        //let t be the longer string
        if (s.size() > t.size()) {
            swap(s, t);
        }
        int m = s.size();
        int n = t.size();
        //n should be larger than m
        if (n - m > 1) {
            return false;
        }
        int i = 0;
        int difference = n - m;
        while (i < m && s[i] == t[i]) { ++i; }
        if (i == m) {
            return difference > 0;
        }
        if (difference == 0) {
            ++i;
        }
        while (i < m && s[i] == t[i + difference]) { ++i; }
        return i == m;
    }
};
