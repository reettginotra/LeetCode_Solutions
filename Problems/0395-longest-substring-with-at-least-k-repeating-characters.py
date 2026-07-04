class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        ans = 0

        for target in range(1, 27):
            cnt = [0] * 26
            left = right = 0
            unique = at_least_k = 0

            while right < len(s):
                idx = ord(s[right]) - 97
                if cnt[idx] == 0:
                    unique += 1
                cnt[idx] += 1
                if cnt[idx] == k:
                    at_least_k += 1
                right += 1

                while unique > target:
                    idx = ord(s[left]) - 97
                    if cnt[idx] == k:
                        at_least_k -= 1
                    cnt[idx] -= 1
                    if cnt[idx] == 0:
                        unique -= 1
                    left += 1

                if unique == target and unique == at_least_k:
                    ans = max(ans, right - left)

        return ans