class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<bool> result(n + 1, false);
        result[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            result[i] = s2[i - 1] == s3[i - 1] && result[i - 1];
        }
        for (int i = 1; i < m + 1; ++i) {
            result[0] = s1[i - 1] == s3[i - 1] && result[0];
            for (int j = 1; j < n + 1; ++j) {
                result[j] = result[j] && s1[i - 1] == s3[i + j - 1]
                || result[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        return result.back();
    }
};
