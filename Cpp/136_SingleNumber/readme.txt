001.cpp:
Time complexity: O(n)
Space complexity: O(1)
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
可以看下面的answer，题主答题语文堪忧。
https://leetcode.com/discuss/54970/an-general-way-to-handle-all-this-sort-of-questions
这种题目（数组中其他数出现K次剩下一个数出现M次（这里K=2，M=1））其实就是统计32位每个位置1的个数，
然后对32位上的数对M取模，如果结果不为0就说明output里那位为1，其实就是002.cpp的做法。XOR刚好能满足这种情况。
