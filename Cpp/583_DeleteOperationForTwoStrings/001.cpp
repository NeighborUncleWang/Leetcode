class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> cur(n + 1, 0);
        for (int i = 0; i <= m; ++i) {
            vector<int> next(n + 1, 0);
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0) {
                    next[j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    next[j] = cur[j - 1];
                } else {
                    next[j] = 1 + min(cur[j], next[j - 1]);
                }
            }
            cur = move(next);
        }
        return cur.back();
    }
};