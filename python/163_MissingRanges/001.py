class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        next = lower
        res = list()
        f = lambda x, y: str(x) if x == y else str(x) + "->" + str(y)
        for num in nums:
            if num > next:
                res.append(f(next, num - 1))
            next = num + 1
        if upper >= next:
            res.append(f(next, upper))
        return res
