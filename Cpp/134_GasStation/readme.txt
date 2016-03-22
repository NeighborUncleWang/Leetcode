001.cpp:
Time complexity: O(n)
Space complexity: O(1)
如果[i, j]这段index里面累积的gas(sum)小于0，那么[i, j]之间所有index都不能作为起点。因为假如 i < k <=j 作为起点，因为[i, k]这一段累积的sum肯定是正的，否则在这一段就会因为sum < 0而退出。因为sum[i, k] > 0, sum[i, k] + sum[k, j] < 0, 所以sum[k, j]肯定小于0. 这样就把[i, j]这段的index全部淘汰掉了。所以找到的startPoint一定是没有被淘汰的，我们只要取不回被淘汰里面的第一个就行了。然后根据total来判断整个问题是否有解，有解的话不被淘汰的第一个index值就可以作为startPoint。
参考:
http://blog.csdn.net/linhuanmars/article/details/22706553
https://leetcodenotes.wordpress.com/2013/11/21/leetcode-gas-station-%E8%BD%AC%E5%9C%88%E7%9A%84%E5%8A%A0%E6%B2%B9%E7%AB%99%E7%9C%8B%E8%83%BD%E4%B8%8D%E8%83%BD%E8%B5%B0%E4%B8%80%E5%9C%88/
这题有点像Moore Voting算法，都是先维护一个唯一的candidate，然后再verify这个唯一的candidate是否是正确结果。不过这题两个过程能够同时进行。total >= 0是用来验证这个结果对不对，前面sum < 0是用来寻找唯一的candidate