001.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
Reference:
https://leetcode.com/discuss/33884/11ms-c-solution-concise
这是用top-down memoization dp 的结果.我写过bottom-up的dynamic programming，想法一模一样，结果不能通过OJ，会碰到TLE，这OJ有问题。
Reference里每次递归都传入整个string，其实只要传入endIndex就行，因为startIndex都是0.
002.cpp:
Time complexity: O(2^n)(NP problem)
Space complexity: O(2^n)
The dp version. Uses another matrix backTracking to trace the solution. Just as the CLRS's LCS problem.
https://github.com/hongtaocai/code_interview/blob/master/cpp/WordBreakII.cpp
003.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
The DFS(brute force) version. First run isBreakable to test whether the string is breakable.
