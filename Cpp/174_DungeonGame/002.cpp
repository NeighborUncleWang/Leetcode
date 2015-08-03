class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int column = dungeon[0].size();
        int large = column > row ? column : row;
        int small = column > row ? row : column;
        vector<int> dp(small + 1, INT_MAX);
        for (int i = large - 1; i >= 0; --i) {
            if (i == large - 1) {
                dp.back() = 1;
            } else {
                dp.back() = INT_MAX;
            }
            //不能单纯在最外的loop直接把dp.back()赋值为1，也不能每次结束j循环就把dp.back()赋值为INT_MAX，而要分情况讨论
            //这道题即使把dp数组最外多加一圈冗余区域来也无法很好地避免边界条件的判断，不像CLRS书中的LCS那么美观，所以还不如直接判断边界条件写不同的赋值式子
            //还有CLRS书上解LCS题为什么要设置index为0的无效区域，直接对index为1的有效边界区域单独用for loop赋值不行吗？
            //感觉也可以啊
            for (int j = small - 1; j >= 0; --j) {
                int value = column == small ? dungeon[i][j] : dungeon[j][i];
                dp[j] = max(-value + min(dp[j], dp[j + 1]), 1);
            }
        }
        return dp[0];
    }
};
