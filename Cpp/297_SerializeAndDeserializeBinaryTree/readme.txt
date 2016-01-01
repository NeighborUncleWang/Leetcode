001.cpp:
Time complexity: O(n)
Space complexity: O(n)
This solution uses stringstream.
Reference:
https://leetcode.com/discuss/66147/recursive-preorder-python-and-c-o-n
002.cpp:
Time complexity: O(n)
Space complexity: O(n)
This solution uses string.
有返回值的递归就是先想好递归出口的返回值是什么，比如这道题是当temp == "*"时，返回nullptr.
然后再想好正常情况下的返回值是什么，比如这道题是return node.