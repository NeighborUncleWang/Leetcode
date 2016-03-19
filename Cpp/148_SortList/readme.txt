001.cpp
Time complexity: O(nlogn)
Space complexity: O(logn)
Use recursive merge-sort to sort the array, if we don't count the stack, then it use constant space.
Reference:
https://leetcode.com/discuss/1709/have-pretty-mergesort-method-anyone-speed-reduce-memory-usage
002.cpp:
Time complexity: O(nlogn)
Space complexity: O(logn)
记录一个头节点，每visit一次把头结点后移一位。其实不一定要用指针的指针来进行操作，可以用指针的reference
但是002.cpp速度和001.cpp基本一样(60ms VS 60ms)，不知道为什么
Reference:
http://fisherlei.blogspot.com/2013/12/leetcode-sort-list-solution.html