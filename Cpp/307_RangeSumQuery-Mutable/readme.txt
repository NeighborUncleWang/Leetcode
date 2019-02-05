001.cpp:
Time complexity:
Construct: O(n)
Update: O(logn)
Query: O(logn)
Space complexity: O(n)
The segment-tree version.
SegmentTree还可以用来找某个range里比如nums[0]~nums[5]的最小值最大值，
只要把每个节点存储的sum改成min或则max再做一些其他相应变化就行。
Reference:
https://leetcode.com/discuss/70202/17-ms-java-solution-with-segment-tree
http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
002.cpp:
Time complexity:
Construct: O(n)
Update: O(logn)
Query: O(logn)
Space complexity: O(n)
The binary-indexed tree version.
Reference:
这是一篇topcoder上关于bit的文章的翻译和原文，觉得写得很好，让我理解了很多:
http://www.hawstein.com/posts/binary-indexed-trees.html
https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
下面是其他references
https://leetcode.com/discuss/70293/java-binary-indexed-tree
http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
https://www.youtube.com/watch?v=CWDQJGaN1gY
003.cpp:
The same as 002.cpp
Tried to delete the redudant updateBIT() function. Others are the same as 002.cpp
