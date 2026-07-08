class Solution(object):
    def repeatedSubstringPattern(self, s):
        n = len(s)
        lps = [0] * n

        j = 0
        for i in range(1, n):
            while j and s[i] != s[j]:
                j = lps[j - 1]

            if s[i] == s[j]:
                j += 1
                lps[i] = j

        x = lps[-1]
        return x > 0 and n % (n - x) == 0