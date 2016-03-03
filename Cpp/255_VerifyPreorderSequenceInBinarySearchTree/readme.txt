001.cpp:
Time complexity: O(n)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space
其实这道题的意思是如果根据preorder里的value判断是不是满足BST的定义，即left < root < right.
这题只要输入有可能是BST的valid preorder sequence就行了。而不是说一个非valid的BST能产生和输入一样的preorder sequence就错。
比如 5 , sequence是[5,4,10]，5  也能产生这个sequence，所以对这个输入应该返回true。
   /					   / \
  4	                      4   10
   \
    10