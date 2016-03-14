001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/19746/my-pretty-simple-code-to-solve-it
这题我完全不懂怎么回事。首先discussion里的答案和153. Find Minimum in Rotated Sorted Array discussion里的一样，用的都是wikipedia上Deferred detection of equality的binary search.
还有为什么nums[middle] > nums[high]能消掉一半我也不理解（好像理解了，nums[middle] > nums[high]）最小值只能在右边，但是为什么正常的binary search（low <= high, high = middle + 1）版本又不能工作，我又不懂了。
这题其实worst case已经是O(n)了，TMD用毛binary search，直接return *min_element(nums.begin(), nums.end())算了。