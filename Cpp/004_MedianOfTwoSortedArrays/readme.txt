001.cpp:
Time complexity: O(log(m + n))
Space complexity: O(log(m + n))
002.cpp:
Time complexity: O(log(m + n))
Space complexity: O(log(m + n))
001.cpp 每次移走1/2，002.cpp每次移走1/4，但是感觉时间上应该一样的，因为找到第k个元素只需要移走前k - 1个元素，所以只有移走的lower part部分影响运行时间。至少我是这么认为的，具体还要看CLRS怎么说。
Reference:
http://blog.csdn.net/linhuanmars/article/details/19905515
http://blog.csdn.net/yutianzuijin/article/details/11499917
http://blog.csdn.net/zxzxy1988/article/details/8587244
http://fisherlei.blogspot.com/2012/12/leetcode-median-of-two-sorted-arrays.html
