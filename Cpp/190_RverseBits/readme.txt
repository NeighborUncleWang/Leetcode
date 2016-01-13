001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
http://wlcoding.blogspot.com/2015/03/reverse-integer-bits.html?view=sidebar
Follow-up:
把int分成4bytes，每个byte分别reverse然后存到hash table里（也可以所有int的reverse都存到hash table里，这里就是一个时间空间的trade-off）
Reference:
https://leetcode.com/discuss/27328/java-solution-and-optimization