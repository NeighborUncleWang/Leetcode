001.cpp:
Time complexity: O(n)
Space compelxity: O(1)
Reference:
https://leetcode.com/discuss/59015/simple-o-n-java-solution-using-insert-index
https://leetcode.com/discuss/76517/a-95-26%25-beat-rate-solution
002.cpp:
Time complexity: O(n)
Space compelxity: O(1)
Reference:
An algorithm derived from CLRS's partition function in quicksort.

An article：
https://leetcode.com/articles/move-zeroes/
这篇文章有问题，其实001.cpp应该比002.cpp好，比如当nums = [0, 1, 1, 1, 1, 1, 1, 1]时. Approach 002.cpp would end up with 3N times of write and 3N times of read, which is much worse than Approach 001.cpp (N write and N read).