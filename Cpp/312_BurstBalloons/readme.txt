001.cpp:
Time complexity: O(n^3)
Space complexity: O(n^2)
这题和471. Encode String with Shortest Length类似，都是以length作为最外层循环变量进行dp。这题之所以不能像471那样把dp[start][end]直接分成dp[start][i], dp[i + 1][end]两个sub-problem是因为这样的话不知道两个sub-problem是否能同时满足（有可能左半边留下的最后一个气球不是右半边取到最优值时希望得到的）。但是如果单独拿出一个最后爆掉的气球来分隔两个sub-problem，那么左右两个sub-problem的边界条件就确定了，左边最后一个气球引爆的时候右边的气球一定是整个[start, end]range里最后一个引爆的气球。
Reference:
https://leetcode.com/discuss/72186/c-dynamic-programming-o-n-3-32-ms-with-comments
https://leetcode.com/discuss/72216/share-some-analysis-and-explanations