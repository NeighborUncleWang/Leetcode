001.cpp:
Time complexity: O(n * k)
Space complexity: O(n * k)
References:
https://leetcode.com/discuss/57669/understanding-easily-modified-different-situations-solution
When the input is 2, [5,6,7,8,9,10,15], 当程序执行完两个矩阵值：
The Release Matrix:
0   0   0   
0   1   1   
0   2   2   
0   3   3   
0   4   4   
0   5   5   
0   10   10   
The Hold Matrix:
-5   -5   -5   
-5   -5   -5   
-5   -5   -5   
-5   -5   -5   
-5   -5   -5   
-5   -5   -5   
-5   -5   -5  
002.cpp:
Time complexity: O(n * k)
Space complexity: O(k)
This is the 1D dp version.
References:
https://leetcode.com/discuss/25603/a-concise-dp-solution-in-java
https://leetcode.com/discuss/32338/share-my-c-dp-solution-with-o-kn-time-o-k-space-10ms