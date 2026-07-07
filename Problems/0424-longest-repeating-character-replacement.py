class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        cnt = [0] * 26
        left = 0
        best = 0
        ans = 0

        for right in range(len(s)):
            idx = ord(s[right]) - 65
            cnt[idx] += 1

            if cnt[idx] > best:
                best = cnt[idx]

            while right - left + 1 - best > k:
                cnt[ord(s[left]) - 65] -= 1
                left += 1

            if right - left + 1 > ans:
                ans = right - left + 1

        return ans