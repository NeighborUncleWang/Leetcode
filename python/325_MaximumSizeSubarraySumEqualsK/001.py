class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res, accumulate, sums = 0, 0, {0: -1}
        for idx, num in enumerate(nums):
            accumulate += num
            if accumulate - k in sums:
                res = max(res, idx - sums[accumulate - k])
            if accumulate not in sums:
                sums[accumulate] = idx
        return res
