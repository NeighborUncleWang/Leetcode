class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> cur(2, vector<int>(3, 1));
        //dp[len][i][j]代表序列长度为len时contains at most i 'A' 
        //and contains at most j 'L' at the end of the sequence
        //这里at most j个'L'一定是在末尾，这样才有int val = cur[i][2]
        //因为新的'P'会使得序列最后没有'L'
        for (int len = 1; len <= n; ++len) {
            vector<vector<int>> next(2, vector<int>(3, 0));
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int val = cur[i][2];//...P
                    if (i > 0) val = (val + cur[i - 1][2]) % 1000000007;//....A;
                    if (j > 0) val = (val + cur[i][j - 1]) % 1000000007;//....L
                    next[i][j] = val;
                }
            }
            cur = move(next);
        }
        return cur[1][2];
    }
};