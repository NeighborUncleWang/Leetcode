001.cpp:
Time complexity: O(klogn)
Space complexity: O(klogn)
Referene:
https://leetcode.com/discuss/55486/java-two-stacks-iterative-solution
https://leetcode.com/discuss/71820/java-5ms-iterative-following-hint-o-klogn-time-and-space
这两个方法是一样的，不过第一个方法把第二个方法里二外的两个辅助函数写到一起了，这样更加简洁。
最开始stackPredecessor和stackSuccessor的top节点存储的是最接近target的两个值，一个>=target,一个<target.之后类似merge sort的方法，不断的取两个stack里的值merge。
002.cpp:
Time complexity: O(n)
Space complexity: O(k)
Reference:
看这页的第二个答案
https://leetcode.com/discuss/55240/ac-clean-java-solution-using-two-stacks?show=80270#a80270