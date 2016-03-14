001.cpp:
Time complexity: O(m * n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/15997/any-shortest-o-1-space-solution
这题之所以不用设置row0的tag是因为如果(i > 0 && j > 0)的某一个位置有0，matrix[0][j]本身就会被置为0，所以只要考虑matrix[0][j]里有0然后导致这一行被置成0的情况，这种情况下matrix[0][0]会被置成0，所以到最后row0 都会被置成0。最后之所以要从右下角开始是为了防止第一行看到matrix[0][0] == 0导致row0被置成0，之后的遍历因为row0都是0了，所以整个矩阵就错误地被置成0，真的面试还是用002.cpp的方法吧，否则自己都和面试官解释不清楚。
002.cpp:
Time complexity: O(m * n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/38186/my-ac-java-o-1-solution-easy-to-read