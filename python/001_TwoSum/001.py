class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for idx, num in enumerate(nums):
            if target - num in dict:
                return [idx, dict[target - num]]
            else:
                dict[num] = idx
