001.cpp:
Time complexity: O(n^2)
Space complexity: O(1)
002.cpp:
Time complexity: O(n^2)
Space complexity: O(1)
003.cpp:
Time complexity: O(n^2)
Space complexity: O(n^2)
The DP version. Sometimes it can pass the OJ, sometimes it will Time Limit Exceeded. The time cost is 640~648ms. It's even slower than Java(476ms), maybe I should change vector<vecotr<bool>> to bool[n][n]. The first two versions only cost 92ms.
如果用bool P[n][n]会出问题，程序应该没错，但是执行结果就是不对P[2][6] = true（这里应该为false才对）, p[3][5] = false(这个符合预期)。
004.cpp:
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
