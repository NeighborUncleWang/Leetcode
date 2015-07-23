class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> result(n + 1, 0);
        for (int i = 0; i < n + 1; ++i) {
            result[i] = i;
        }
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; i + j - 1 < n && i - j - 1 >= 0 && s[i + j - 1] == s[i - j - 1]; ++j) {
                result[i + j] = min(result[i + j], result[i - j - 1] + 1);
            }
            for (int j = 1; i + j - 1 < n && i - j >= 0 && s[i + j - 1] == s[i - j]; ++j) {
                result[i + j] = min(result[i + j], result[i - j] + 1);
            }
        }
        return result.back() - 1;
    }
};
