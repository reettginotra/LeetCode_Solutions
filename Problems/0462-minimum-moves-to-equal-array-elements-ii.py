class Solution(object):
    def minMoves2(self, nums):
        nums.sort()
        mid = nums[len(nums) >> 1]
        ans = 0

        for x in nums:
            ans += abs(x - mid)

        return ans