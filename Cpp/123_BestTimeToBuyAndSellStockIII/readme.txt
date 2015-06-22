001.cpp:
Time complexity: O(n)
Space compelxity: O(n)
Idea: sum = max(sum, maxLeft[i] + maxRight[i])
There is another more general solution that can solve this problem when at most k transactions are allowed: http://blog.csdn.net/linhuanmars/article/details/23236995. It is hard to understand especially why local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff) 
