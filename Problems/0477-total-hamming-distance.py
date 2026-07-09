class Solution(object):
    def totalHammingDistance(self, nums):
        n = len(nums)
        ans = 0

        for b in range(30):
            ones = 0
            mask = 1 << b

            for x in nums:
                if x & mask:
                    ones += 1

            ans += ones * (n - ones)

        return ans