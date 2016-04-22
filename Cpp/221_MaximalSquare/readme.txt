001.cpp:
Time complexity: O(m * n)
Space complexity: O(min(m, n))
dp[i][j]是指以(i - 1, j - 1)点作为正方形右下角所能得到的最大边长
002.cpp:
Time complexity: O(m * n)
Space complexity: O(m * n)
Reference:
https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
这题也可以用来解这个矩阵里能找到多少个正方形，因为dp[i][j]记录了以(i - 1, j - 1)点作为正方形右下角所能得到的最大边长，那么以(i - 1, j - 1)作为正方形右下角的正方形个数就是dp[i][j]
只要把dp所有entries加起来就是所有正方形的个数。