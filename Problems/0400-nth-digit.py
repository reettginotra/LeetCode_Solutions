class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        digits = 1
        start = 1
        count = 9

        while n > digits * count:
            n -= digits * count
            digits += 1
            start *= 10
            count *= 10

        num = start + (n - 1) // digits
        return int(str(num)[(n - 1) % digits])