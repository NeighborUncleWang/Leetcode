class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> indices(256, -1);
        int distinct = 0, res = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (indices[s[right]] == -1) {
                ++distinct;
            }
            indices[s[right]] = right;
            if (distinct > k) {
                int new_left = INT_MAX;
                for (int index: indices) {
                    if (index != -1) {
                        new_left = min(new_left, index);
                    }
                }
                indices[s[new_left]] = -1;
                --distinct;
                left = new_left + 1;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
