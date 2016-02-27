class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for (char ch : t) {
            ++map[ch];
        }
        int left = 0;
        int right = 0;
        int count = t.size();
        int minLength = INT_MAX;
        int minLeft = 0;
        while (right < s.size()) {
            if (--map[s[right++]] >= 0) {
                --count;
            }
            while (count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    minLeft = left;
                }
                if (++map[s[left++]] == 1) ++count;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};