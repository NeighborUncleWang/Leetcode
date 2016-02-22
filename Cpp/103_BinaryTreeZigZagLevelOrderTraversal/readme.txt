001.cpp:
Time complexity: O(n)
Space complexity: O(n)
Use a queue, 其实也可以!leftToRight的时候先将row reverse一下，再push_back进result
Reference:
https://leetcode.com/discuss/28080/version-queue-without-reverse-operation-using-size-each-level

Another solution use deque, but it's hard to analysis the order
https://leetcode.com/discuss/50994/clear-iterative-solution-with-deque-no-reverse