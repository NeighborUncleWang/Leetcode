001.cpp
Time complexity: O(logn)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/15946/simplest-and-fastest-c-solution-o-lg-n-you-cant-beat-this
Reference是wikipedia上Deferred detection of equality版本的binary search，我自己用的是normal的bianry search，所以判断条件也不一样，如果我用nums[middle] > nums[high]的条件会出错，估计是high = middle - 1那里会跳过正确的答案。