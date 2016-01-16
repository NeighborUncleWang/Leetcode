Suppose m is the row size and n is column size.
时间复杂度是我自己推的，感觉leetcode这篇文章有点问题.面试时候碰到还是直接用001.cpp好了。
关于复杂度分析：
https://leetcode.com/discuss/51108/is-theres-a-o-log-m-log-n-solution-i-know-o-n-m-and-o-m-log-n
001.cpp:
Time complexity: O(m + n)(n is the dimension of the matrix, the perimeter, not area)
Space complexity: O(1)
002.cpp:
Time complexity: O((mn)^log4(3)) Since T(mn) = 3(mn/4) + c
Space complexity: O((mn)^log4(3))
The 002.cpp is slower and more complicated than 001.cpp. Damn it.
003.cpp:
Time complexity: O((mn)^0.5) Since T(mn) = 2T(mn/4) + logm
Space complexity: O(n)
Use binary parition to partition the column. Use binary search to locate the partition row.
Reference:
http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
It seems the 001.cpp is the simplest and fastest.
001.cpp: 368ms
002.cpp: 460ms
003.cpp: 368ms

