class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack = []

        for c in num:
            while k and stack and stack[-1] > c:
                stack.pop()
                k -= 1
            stack.append(c)

        while k:
            stack.pop()
            k -= 1

        ans = ''.join(stack).lstrip('0')
        return ans if ans else "0"