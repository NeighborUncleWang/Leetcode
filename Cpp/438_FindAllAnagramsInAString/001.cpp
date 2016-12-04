class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> map(256, 0);
        for (char ch : p) {
            ++map[ch];
        }
        int left = 0, right = 0, count = p.size();
        vector<int> result;
        while (right < s.size()) {
            if (map[s[right++]]-- > 0) {
                --count;
            }
            if (count == 0) {
                result.push_back(left);
            }
            if (right - left == p.size() && map[s[left++]]++ >= 0) {
                ++count;
            }
        }
        return result;
    }
};