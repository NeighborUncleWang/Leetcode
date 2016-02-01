001.cpp:
Time complexity: O(m * n)
Space complexity: O(min(m, n))
002.cpp:
Time complexity: O(m * n)
Space complexity: O(m * n)
002.cpp is the original naive version. 001.cpp is the improved one.
Reference:
https://leetcode.com/discuss/11694/my-dp-solution-in-c

There is a BFS version:
https://leetcode.com/discuss/19973/8ms-c-solution-using-bfs-with-explanation
不过看不太懂，尤其不懂为什么要用unordered_map存储找过的点，BFS不是应该不会有重复找过的点的吗?
想明白了，是因为(1,1)可以由(0,0)->(0,1)->(1,1)或者(0,0)->(1,0)->(1,1)得到,所以(1,1)有可能被
重复找