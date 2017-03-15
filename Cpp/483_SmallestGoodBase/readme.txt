001.cpp:
Time complexity: O(logn)
Space complexity: O(1)
Reference:
https://discuss.leetcode.com/topic/76368/python-solution-with-detailed-mathematical-explanation-and-derivation
注释
n = k^m + ... + 1 < (k+1)^m这个不等式只在m >= 2的时候成立，m=1的时候n = k + 1 = (k + 1)^1