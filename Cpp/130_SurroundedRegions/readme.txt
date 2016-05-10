001.cpp:
Time complexity: O(m * n)
Space complexity: O(m + n)
BFS version. BFS的complexity应该是O(m + n)没错，因为如果从最中间的点开始搜索, BFS的queue里最多元素的情况只有以矩形对角线的一半为边长的菱形的周长，对角线的一半是O(m + n)(三角形两边之和大于第三边)
Reference:
http://blog.csdn.net/linhuanmars/article/details/22904855
002.cpp:
Time complexity: O(m * n)
Space complexity: O(m + n)
DFS我感觉space complexity是O(m * n), 因为从中间开始有可能把所有点都push到stack上。
DFS做法，但是会引起stack overflow(run time error).
代码是对的，引起的原因以及pass的方法可以看下面这篇里的评论：
https://leetcode.com/discuss/42445/a-really-simple-and-readable-c-solution%EF%BC%8Conly-cost-12ms