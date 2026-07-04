#The trick is using the frequency of each number.

from collections import Counter

class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = Counter(nums)
        ans = 1

        # Handle number 1 separately
        if 1 in cnt:
            ans = max(ans, cnt[1] if cnt[1] % 2 else cnt[1] - 1)

        for x in cnt:
            if x == 1:
                continue

            cur = x
            length = 0

            while cnt[cur] >= 2:
                length += 2
                cur *= cur

            if cnt[cur] >= 1:
                length += 1
            else:
                length -= 1

            ans = max(ans, length)

        return ans