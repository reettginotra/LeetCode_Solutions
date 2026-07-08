class Solution(object):
    def hammingDistance(self, x, y):
        x ^= y
        ans = 0

        while x:
            x &= x - 1
            ans += 1

        return ans