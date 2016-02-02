001.cpp:
Time complexity: O(n^2)
Space complexity: O(n^2)
Reference:
http://blog.csdn.net/linhuanmars/article/details/22837047
code ganker res储存的是能切成多少份，所以要减1，我储存的是要切几次，所以不用减1，但是要考虑切割次数位0（即整个字符串是回文的情况）
002.cpp:
Time complexity: O(n^2)
Space complexity: O(n)
002.cpp is much faster than 001.cpp(12ms VS 84ms)
Reference:
https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
