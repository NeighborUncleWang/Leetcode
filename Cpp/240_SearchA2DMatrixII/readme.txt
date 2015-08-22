001.cpp:
Time complexity: O(n)(n is the dimension of the matrix, the perimeter, not area)
Space complexity: O(1)
002.cpp:
Time complexity: O(n^1.58)
Space complexity: O(n^1,58)
The 002.cpp is slower and more complicated than 001.cpp. Damn it.
003.cpp:
Time complexity: O(n)(T(n) = 2T(n/2) + logn)
Space complexity: O(n)
Use binary parition to partition the column. Use binary search to locate the partition row.
Reference:
http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
It seems the 001.cpp is the simplest and fastest.
001.cpp: 368ms
002.cpp: 460ms
003.cpp: 368ms

