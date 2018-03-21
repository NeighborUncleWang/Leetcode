class Solution(object):
    def f(self, x, y): return str(x) if x == y else str(x) + "->" + str(y)
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        next = lower
        res = list()
        for num in nums:
            if num > next:
                res.append(self.f(next, num - 1))
            next = num + 1
        if upper >= next:
            res.append(self.f(next, upper))
        return res
