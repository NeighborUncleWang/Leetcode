001.cpp:
Time complexity: O(3^n)(n是digits的字符串的长度)
Space complexity: O(n)(n是递归搜索树的height)
The recursive version.
http://fisherlei.blogspot.com/2012/12/leetcode-letter-combinations-of-phone.html
代码中有用注释写的对DFS的一些思考
002.cpp:
Time complexity: Q(3^n)
Space complexity: O(3^n)
A good iterative solution using deque:
Reference:
https://leetcode.com/discuss/24431/my-java-solution-with-fifo-queue
003.cpp:
Time complexity: O(3^n)(assume each digit can represent 3 letters, atcually 7 and 9 can represent 4 letters)
Space complexity: O(3^n)
The iterative version.
http://blog.csdn.net/linhuanmars/article/details/19743197
我觉得其实003.cpp更好理解记忆一些。
