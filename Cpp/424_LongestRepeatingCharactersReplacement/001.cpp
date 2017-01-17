class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count = 0, result = 0;
        vector<int> count(26, 0);
        for (int left = 0, right = 0; right < s.size(); ++right) {
            max_count = max(max_count, ++count[s[right] - 'A']);
            while (right - left + 1 - max_count > k) {
                --count[s[left++] - 'A'];
            }
            result = max(result, right - left + 1 - max_count);
        }
        return result;
    }
};