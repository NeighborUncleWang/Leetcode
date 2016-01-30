001.cpp:
Time complexity: O(n^4)
Space complexity: O(n^3)
A 3-dimension DP. 
Reference:
http://blog.csdn.net/linhuanmars/article/details/24506703
002.cpp:
Time complexity: O(2^n)
Space complexity: O(n)
The code for count is used to prune, without this block, the logic is
still right, but will meet TLE problem for the OJ. This solution is much
faster than 001.cpp, interesting;
Reference:
https://leetcode.com/discuss/36470/share-my-4ms-c-recursive-solution
