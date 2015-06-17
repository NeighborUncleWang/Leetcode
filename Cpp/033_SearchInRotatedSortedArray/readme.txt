Time complexity: O(logn)
Space complexity: O(1)
001.cpp first check which region the nums[median] is by comparing it to nums[high], if nums[median] < nums[high], then it means the elements in [median, high] is sorted, so only when the target > nums[median] and target <= nums[high] we need to search the right half. Otherwise we only need to search left half. And we can also locate target when nums[median] >= nums[low].
