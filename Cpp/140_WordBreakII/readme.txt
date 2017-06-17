001.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
这个方法和002.cpp很像，不过这个是把生成的suffixes插到后面，而且hashmap用string当key，这样的话效率没那么高但是代码比较短。
Reference:
https://discuss.leetcode.com/topic/27855/my-concise-java-solution-based-on-memorized-dfs
这里关于worst case为什么complexity是O(2^n)的讨论:
https://discuss.leetcode.com/topic/27855/my-concise-java-solution-based-on-memorized-dfs/41
Consider the input "aaaaaa", with wordDict = ["a", "aa", "aaa", "aaaa", "aaaaa", "aaaaa"]. Every possible partition is a valid sentence, and there are 2^n-1 such partitions. It should be clear that the algorithm cannot do better than this since it generates all valid sentences.
002.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
Reference:
https://leetcode.com/discuss/33884/11ms-c-solution-concise
这是用top-down memoization dp 的结果.我写过bottom-up的dynamic programming，想法一模一样，结果不能通过OJ，会碰到TLE，这OJ有问题。
Reference里每次递归都传入整个string，其实只要传入endIndex就行，因为startIndex都是0.
003.cpp:
Time complexity: O(2^n)(NP problem)
Space complexity: O(2^n)
The dp version. Uses another matrix backTracking to trace the solution. Just as the CLRS's LCS problem.
https://github.com/hongtaocai/code_interview/blob/master/cpp/WordBreakII.cpp
004.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
The DFS(brute force) version. First run isBreakable to test whether the string is breakable.
