001.cpp:
Time complexity: O(2^n)(用了cand这个变量来记录要检测的位来剪枝,13ms)
Space complexity: O(2^n)
Reference:
https://discuss.leetcode.com/topic/61457/c-bit-manipulation-dfs-solution
002.cpp:
Time complexity: O(2^n)(没用cand剪枝402ms)
Space complexity: O(2^n)
Reference:
My solution.
这题基本思路是穷举所有可能的abbr,然后判断这个是不是valid的abbr，如果是，那么就比较试试看能不能update当前最短valid的abbr的长度。注意这题说了所有number不管有几位，全部算成长度为1，比如数字99的长度也是1。
主要思想是用bit mask来快速决定是不是valid，其实和408. Valid Word Abbreviation遍历abbr来判断的方法没有本质区别，这题是得益于题设要求满足m <= 21,这样可以用integer的mask来检查。
思路看这篇，讲得比较好：
https://discuss.leetcode.com/topic/61690/python-with-bit-masks

这个是我自己写的abbrLen():
    int abbrLen(int mask, int n) {
        int len = 0;
        for (int i = 0; i < n; ) {
            if (mask & (1 << i)) {
                ++len;
                ++i;
            } else {
                while (i < n && (mask & (1 << i)) == 0) {
                    ++i;
                }
                ++len;
            }
        }
        return len;
    }