001.cpp:
Time complexity: O(n^2)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/32204/simple-c-solution-8ms-13-lines
这题想法就是如果我们碰到相同的字符，abcdeeeeeedcba这种情况，当center指向第一个e时，right会跳过后面所有的e，然后指向最后一个e，可以想象成把中间所有的e看成一个相同的字符，这样一开机left和right都指向这个相同的字符，然后开始寻找最长回文字符串。这样可以避免区分字符串长度为奇数和偶数的情况。
002.cpp
Time complexity: O(n)
Space copmlexity: O(n)
The Manacher's Algorithm.
Reference:
http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
http://www.cnblogs.com/grandyang/p/4464476.html
http://www.felix021.com/blog/read.php?2040
http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
Manacher's Algorithm时间复杂度分析:
http://www.douban.com/note/321468038/
