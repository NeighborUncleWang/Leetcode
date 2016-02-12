001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/13953/a-simple-java-solution
Sort the intervals based on their start time. Then create a newInterval, if the next interval overlap with current newInterval, then check whether the newInterval can have a larger end time. If we find the next interval has a gap between current newInterval, then we push_back the current newInterval to the result vector and set newInterval to be intervals[i].
002.cpp 的写法可以避免for loop执行完在执行一句result.push_back()，这种写法对这个题目没什么用，但是如果for loop里else block里的代码很长，还是能使代码变短的