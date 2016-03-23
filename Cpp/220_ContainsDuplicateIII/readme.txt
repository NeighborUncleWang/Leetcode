001,cpp:
Time complexity: O(n)
Space complexity: O(k)
Bucket size must only be t or t + 1. if t+2, then one bucket may contain 2 numbers; if t-1, then bucket[i] and bucket[i+2] may contain a pair of number, whose distance is t.
Bucket size用t+1可以避免判断t==0的边界条件
(long long)t + 1必须有，因为有t==INT_MAX的test case
这题其实可以把INT_MAX换成input nums中的最小值。
这题同时也给出了当input是int时bucket sort怎么计算bucket的index的提示。假设bucket sort里nums size为n。那么index = (num - min) * 1.0 / (max - min) * n;
Reference:
https://leetcode.com/discuss/38206/ac-o-n-solution-in-java-using-buckets-with-explanation
002.cpp:
Time complexity: O(nlogk)
Space complexity: O(k)
Reference:
https://leetcode.com/discuss/45120/c-using-set-less-10-lines-with-simple-explanation
