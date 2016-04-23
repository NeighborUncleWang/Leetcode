001.cpp:
Time complexity: O(height(tree))
Space compleixty: O(1)
Reference:
https://leetcode.com/discuss/61105/java-python-solution-o-h-time-and-o-1-space-iterative
002.cpp:
Time complexity: O(height(tree))
Space compleixty: O(1)
Reference:
https://leetcode.com/discuss/59787/share-my-java-recursive-solution?show=88018#c88018
这题如果node有parent pointer的话，可以参考CLRS书上的做法
或者看这个链接:
http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
分两种情况:
1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it’s parent. The parent of such a node is the succ.
第二种情况就是找到某个parent，满足:parent的left != nullptr, 然后maxValue(parent->left)刚好等于node.这样说明parent就是node的successor.