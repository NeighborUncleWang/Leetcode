001.cpp time complexity is O(2n), space complexity is O(2n). We do the scan twice: from left to right and from right to left. Need two vectors to contain the intermediate result.
http://blog.csdn.net/linhuanmars/article/details/20888505
002.cpp has time complexity O(n), space complexity O(1). This is a better solution, harder to think. Block contains the accumulative value of height[i], sum means the whole area including the water and the black block in the graph.
http://tsien.github.io/leetcode/2015/06/04/Q042.html
003.cpp:
Time complexity: O(n)
Space complexity: O(1)
Easier to understand than 002.cpp.
http://www.cnblogs.com/grandyang/p/4402392.html
