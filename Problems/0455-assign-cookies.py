class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()

        i = j = 0
        m = len(g)
        n = len(s)

        while i < m and j < n:
            if s[j] >= g[i]:
                i += 1
            j += 1

        return i