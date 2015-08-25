001.cpp:
Time complexity: o(n + m)
Space complexity: O(m)
n is the size of haystack
m is the size of needle
002.cpp:
Time complexity: O(n * m)(n is the size of haystack, m is the size of needle)
Space complexity: O(1)
003.cpp:
Time complexity: O(n * m)
Sapce complexity: O(1)
Almost the same as 001.cpp, just avoid use foundNeedle variable.
004.cpp:
Time complexity: O(n * m)
Space complexity: O(n)
I think this solution is stupid. Since the hash function may takes O(m) time. The speed is slower than 001.cpp and 002.cpp(8ms Vs 4ms).(actually is the substr method which will take O(m) time, this is still a O(m*n) solution instead of O(n))
There are some other solutions for this problem:
A KMP version:
http://fisherlei.blogspot.com/2012/12/leetcode-implement-strstr.html
A rolling hash version(This may cause the hashcode overflow):
http://blog.csdn.net/linhuanmars/article/details/20276833#reply
