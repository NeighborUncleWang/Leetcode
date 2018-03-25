class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        cache = dict()
        dic = set(wordDict)
        def dfs(s, dic, cache):
            if s in cache:
                return cache[s]
            res = []
            if s in dic:
                res.append(s)
            for i in range(1, len(s)):
                prefix = s[0:i]
                if prefix in dic:
                    suffix = s[i:]
                    right = dfs(suffix, dic, cache)
                    for r in right:
                        res.append(prefix + ' ' + r)
            cache[s] = res
            return res
        return dfs(s, dic, cache)
