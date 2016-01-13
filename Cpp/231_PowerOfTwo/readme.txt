001.cpp, 002.cpp:
Time complexity: O(1)
Space complexity: O(1)
http://wlcoding.blogspot.com/2015/07/power-of-two.html?view=sidebar
003.cpp:
Time complexity: O(1)
Space complexity: O(1)
因为n & -n得到的结果是n只含n最后一位1的整数，所以只要判断这个数和n是否相等就行
（从binary indexed tree找parent得到的灵感）
Reference:
https://leetcode.com/discuss/43875/using-n%26-n-1-trick