001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Idea: iterative version
002.cpp:
Time complexity: O(n)
Space complexity: O(n)
Idea: recursive version, the space complexity is for the recursive stack.
Reference:
https://leetcode.com/discuss/34474/in-place-iterative-and-recursive-java-solution
003.cpp:
Time complexity: O(n)
Space complexity: O(n)
另一种递归写法，这种写法可以在下一次call helper function之前执行current->next = predecessor,但是需要先记录current->next.