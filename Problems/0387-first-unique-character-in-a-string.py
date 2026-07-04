class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = [0] * 26

        for c in s:
            cnt[ord(c) - 97] += 1

        for i, c in enumerate(s):
            if cnt[ord(c) - 97] == 1:
                return i

        return -1