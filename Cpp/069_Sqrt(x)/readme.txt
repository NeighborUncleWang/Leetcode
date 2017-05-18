001.cpp:
Time complexity: O(logn)
Space complexity: O(1)
其实不加 if (mid <= x / mid && mid + 1 > x / (mid + 1))的判断最后的时候return start也能pass OJ。
注意start要设置成1而不是0，防止mid = 0然后出现除数为0的情况。
还可以用牛顿法解这题:
http://blog.csdn.net/linhuanmars/article/details/20089131
https://leetcode.com/discuss/58631/3-4-short-lines-integer-newton-every-language
002.cpp:
Time complexity: O(logn)
Space complexity: O(1)
My shorter solution.