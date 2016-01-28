001.cpp:
Time complexity: O(n^2)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/5337/dp-solution-for-triangle
002.cpp:
Time complexity: O(n^2)
Space complexity: O(n)
My solution, from bottom row to top row. The trick is that you should caculate the reuslt of each line from size() - 1 to 0, not 0 to size() - 1. This can avoid lose the result of previous line when calculate the result of current line.
