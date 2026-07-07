class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        x = 0
        s = 0

        for c in str(n):
            if c != '0':
                d = ord(c) - 48
                x = x * 10 + d
                s += d

        return x * s