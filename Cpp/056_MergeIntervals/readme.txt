001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/13953/a-simple-java-solution
Sort the intervals based on their start time. Then create a newInterval, if the next interval overlap with current newInterval, then check whether the newInterval can have a larger end time. If we find the next interval has a gap between current newInterval, then we push_back the current newInterval to the result vector and set newInterval to be intervals[i].
