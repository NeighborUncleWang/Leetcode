001.cpp:
Time complexity: O(logn)(n is the return value)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
002.cpp:
Time complexity: O(logn)
Space complexity: O(1)
Reference:
http://blog.csdn.net/linhuanmars/article/details/20024907
003.cpp:
Time complexity: O(logn)
Space complexity: O(1)
方法和002.cpp一样，但是避免用long long，用了unsigned int，如果面试官问如何避免使用size更大的type(因为本身输入就有可能是long long类型，那样001.cpp和002.cpp就都没办法了)可以用这个答案。否则还是用转化成long long的做法好，可以避免考虑很多corner case。