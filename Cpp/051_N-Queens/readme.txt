001.cpp:
Time complexity: O(n*n^n)(有n^n种情况，每种情况检查isValid的时候都要O(n）时间)
Space complexity: O(n)
DFS solution.
Reference:
https://leetcode.com/discuss/13100/accepted-auxillary-space-o-n-using-dfs-cpp
http://blog.csdn.net/linhuanmars/article/details/20667175
002.cpp:
Time complexity: O(n^n)(有n^n种情况，每种情况检查isValid的时候只要O(1)时间)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/35128/accepted-solution-use-backtracking-bitmask-easy-understand