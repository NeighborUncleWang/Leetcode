class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int row = M.size(), col = row ? M[0].size() : 0;
        vector<vector<int>> current(col + 2, vector<int>(4, 0));
        int res = 0;
        for (int i = 1; i <= row; ++i) {
            vector<vector<int>> next(col + 2, vector<int>(4, 0));
            for (int j = 1; j <= col; ++j) {
                if (M[i - 1][j - 1] == 1) {
                   next[j][0] = next[j - 1][0] + 1;
                   next[j][1] = current[j][1] + 1;
                   next[j][2] = current[j - 1][2] + 1;
                   next[j][3] = current[j + 1][3] + 1;
                   res = max({res, next[j][0], next[j][1], next[j][2], next[j][3]});
                }
            }
            current = move(next);
        }
        return res;
    }
};