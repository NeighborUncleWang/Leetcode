001.cpp:
Time complexity: O(n)(n is the length of string s)
Space complexity: O(l * m)(l is the length of word, m is the length of words)
Use two pointer to maintain a window.
http://blog.csdn.net/linhuanmars/article/details/20342851#reply
This version is significantly faster than 002.cpp(52ms Vs 772ms)
002.cpp:
Time complexity: O(n - m + 1) * (l * m)
Space complexity: O(l * m)
A brute force solution:
http://fisherlei.blogspot.com/2013/01/leetcode-substring-with-concatenation.html
