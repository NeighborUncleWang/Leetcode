class Solution:
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        n = len(s)
        mask = [False] * n
        for word in dict:
            for i in range(n):
                if (s[i:].startswith(word)):
                    mask[i:i + len(word)] = [True] * (len(word))
                    i += len(word) - 1
        ans = []
        for incl, grp in itertools.groupby(zip(s, mask), lambda z: z[1]):
            if incl: ans.append("<b>")
            ans.append("".join(z[0] for z in grp))
            if incl: ans.append("</b>")
        return "".join(ans)
