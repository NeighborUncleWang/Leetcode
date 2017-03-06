class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int L = n; L > 0; --L) {
            for (int R = L + 1; R <= n; ++R) {
                dp[L][R] = INT_MAX;
                //i一定要从L开始而不是L+1,否则会导致n=2返回INT_MAX
                //同时i不能达到R,否则dp[i + 1][R]会越界
                //为什么i不能达到R,或者这么考虑:
                //I try each possible x in the range 
                //(except hi, which is pointless because hi-1 
                //costs less and provides more information)
                //from stephan pochmann's post
                for (int i = L; i < R; ++i) {
                    //在[L,R]范围内选择哪个i是当前玩家可以控制的
                    //猜测到的i和最终target的关系是当前玩家不能控制的
                    //所以说这个游戏要求的是最坏的情况下最少需要多少钱保证能赢
                    //最坏情况是指没次猜的结果都导致后面要更多钱(max(dp[L][i - 1], dp[i + 1][R]))
                    //然后从这些最坏情况里选出一个猜测的值i使得最坏的情况输掉的钱最少
                    dp[L][R] = min(dp[L][R], i + max(dp[L][i - 1], dp[i + 1][R]));
                }
            }
        }
        return dp[1][n];
    }
};