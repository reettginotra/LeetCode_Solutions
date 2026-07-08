class Solution(object):
    def findSubstringInWraproundString(self, s):
        dp = [0] * 26
        k = 0

        for i in range(len(s)):
            if i and ((ord(s[i]) - ord(s[i - 1])) % 26 == 1):
                k += 1
            else:
                k = 1

            idx = ord(s[i]) - 97
            if k > dp[idx]:
                dp[idx] = k

        return sum(dp)