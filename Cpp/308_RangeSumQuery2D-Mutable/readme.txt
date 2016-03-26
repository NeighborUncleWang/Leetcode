001.cpp:
Time complexity: O(log(m)*log(n)) for query and update
Space complexity: O(mn)
2-D Binary Indexed Tree
Reference:
https://leetcode.com/discuss/71025/c-quad-tree-736ms-and-indexed-tree-492ms-based-solutions
002.cpp:
Time complexity: O(max(m, n))
Space complexity: O(mn)
Quad Tree(it does not equals to 2-D segment tree)
Reference:
https://leetcode.com/discuss/71025/c-quad-tree-736ms-and-indexed-tree-492ms-based-solutions
002.cpp速度比001.cpp慢了很多，这里用了一个技巧，update的时候先search到leaf节点，然后再回溯回来update父节点，这样可以避免适用diff变量，不需要存一个matrix的拷贝。