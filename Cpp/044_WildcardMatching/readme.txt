001.cpp:
Time complexity: O(m * n)
Space complexity: O(m * n)
2D DP solution.
This is a good explanation to this solution:
http://www.1point3acres.com/bbs/thread-118735-1-1.html
002.cpp:
Time complexity: O(m * n)
Space complexity: O(n)(n is the size of string p)
1D DP solution.
003.cpp:
Time complexity: O(m * n)(the author claims this a linear solution, why?)
I think the time complexity is O(p * (s - p))
Consider this case:
s = "aaaaaaaaaaaaaaaaaaaab"
p = "*aaaaaaaaaaaaaaaaaab"
Space complexity: O(1)
A greedy solution.
Reference:
https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution
004.cpp:
Time complexity: O(?)
Space complexity: O(?)
This solution has a TLE problem, I am not sure whether it is right.
Reference:
http://wlcoding.blogspot.com/2015/03/regular-expression-matching.html?view=sidebar
Two other articles:
http://blog.csdn.net/lifajun90/article/details/10582733
http://blog.csdn.net/tingmei/article/details/8049926
