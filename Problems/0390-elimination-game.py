class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        head = 1
        step = 1
        left = True

        while n > 1:
            if left or n & 1:
                head += step
            step <<= 1
            n >>= 1
            left = not left

        return head