class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        total = sum(nums)
        cur = 0

        for i, x in enumerate(nums):
            cur += i * x

        ans = cur

        for i in range(n - 1, 0, -1):
            cur += total - n * nums[i]
            if cur > ans:
                ans = cur

        return ans