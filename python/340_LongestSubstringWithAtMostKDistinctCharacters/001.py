class Solution:
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        count = dict()
        left, right, n, distinct, res = 0, 0, len(s), 0, 0
        while right < n:
            count[s[right]] = count.get(s[right], 0) + 1
            if count[s[right]] == 1:
                distinct += 1
            while distinct > k:
                count[s[left]] -= 1
                if count[s[left]] == 0:
                    distinct -= 1
                left += 1
            res = max(right - left + 1, res)
            right += 1
        return res
