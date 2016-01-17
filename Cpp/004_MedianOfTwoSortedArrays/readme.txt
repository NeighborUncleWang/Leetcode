001.cpp:
Time complexity: O(log(m + n))
Space complexity: O(log(m + n))
在这个solution里，k就是index的值，k = 0就代表取第0个元素。
002.cpp每次移走1/4，但是也可以每次像code ganker一样移走1/2, 但是感觉时间上应该一样的，因为找到第k个元素只需要移走前k - 1个元素，所以只有移走的lower part部分影响运行时间。至少我是这么认为的，具体还要看CLRS怎么说。

我觉得001.cpp比002.cpp好，因为001.cpp可以直接扩展到find kth element. 以后还是尽量写001.cpp
Reference:
http://blog.csdn.net/linhuanmars/article/details/19905515

002.cpp:
Time complexity: O(log(min(m, n)))
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/41621/very-concise-iterative-solution-with-detailed-explanation