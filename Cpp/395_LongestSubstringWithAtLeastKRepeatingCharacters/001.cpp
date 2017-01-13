class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
private:
    int helper(string& s, int start, int end, int k) {
        vector<int> count(26, 0);
        for (int i = start; i < end; ++i) {
            ++count[s[i] - 'a'];
        }
        int result = 0;
        for (int i = start; i < end; ++i) {
            //这里不用test count[s[i] - 'a'] > 0
            //因为这个条件肯定满足
            if (count[s[i] - 'a'] < k) {
                return max(helper(s, start, i, k), helper(s, i + 1, end, k));
            }
        }
        return end - start;
    }
};