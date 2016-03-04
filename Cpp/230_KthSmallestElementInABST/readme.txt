001.cpp:
Time complexity: O(nh)
Space complexity: O(1)
002.cpp:
Time complexity: O(k)
Space complexity: O(k)
003.cpp:
Time complexity: O(k)
Space complexity: O(k)
Reference:
https://leetcode.com/discuss/43771/implemented-java-binary-search-order-iterative-recursive
http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
如果可以修改treeNode结构的话可以加入一个新的attribute：rank，srank用来记录以当前node为root的subtree的总node数，这样就省去了001.cpp中调用count函数的时间，达到时间复杂度为O(h), h为tree的height. 这个其实就是CLRS Chapter14 Augmenting Data Structures中的内容。
