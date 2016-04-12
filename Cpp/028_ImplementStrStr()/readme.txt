001.cpp:
Time complexity: o(n + m)
Space complexity: O(m)
n is the size of haystack
m is the size of needle
002.cpp:
Time complexity: O(n * m)(n is the size of haystack, m is the size of needle)
Space complexity: O(1)
The brute-force solution.
A KMP version:
http://fisherlei.blogspot.com/2012/12/leetcode-implement-strstr.html
A rolling hash version(This may cause the hashcode overflow):
http://blog.csdn.net/linhuanmars/article/details/20276833#reply
