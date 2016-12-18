001.cpp:
Time complexity: O(klogk)
Space complexity: O(k)
      2   4   6
   +------------
 1 |  3   5   7
 7 |  9  11  13
11 | 13  15  17
Reference:
https://discuss.leetcode.com/topic/50529/java-9ms-heap-queue-solution-k-log-k
想象每一行或者每一列是一个有序数组，题目就变成合并k个有序数组了。