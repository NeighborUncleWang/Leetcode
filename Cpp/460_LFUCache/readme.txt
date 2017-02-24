001.cpp
Time complexity: O(1)
Space complexity: O(n)
我把每次插入的新元素放在了list的最前面，reference里是放在最后面
找要移除的key的iter时候不要用map_freq[min_freq].end() - 1,因为list是bidirectional iterator, 是不能做-1操作的
还是先找到key最好
这题其实有很多思想很像432. All O`one Data Structure的解法
Reference:
https://discuss.leetcode.com/topic/69436/concise-c-o-1-solution-using-3-hash-maps-with-explanation/2