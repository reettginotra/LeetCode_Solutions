class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0

        while n != 1:
            if n & 1 == 0:
                n >>= 1
            elif n == 3 or (n & 3) == 1:
                n -= 1
            else:
                n += 1
            ans += 1

        return ans