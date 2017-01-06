001.cpp:
Time complexity: O(n)
Space complexity: O(n)
Reference:
https://discuss.leetcode.com/topic/65948/java-solution-using-bfs-topological-sort/7
I don't know why if I change the indegrees to be unordered_map<int, int> then I will always have Memory Limit Exceeded problem for this test case: [1][[1,-9999],[-9999,-9998],[-9998,-9999]]. I think this is a problem from Leetcode.