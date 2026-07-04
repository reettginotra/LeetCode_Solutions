class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        cur = []
        num = 0

        for c in s:
            if '0' <= c <= '9':
                num = num * 10 + ord(c) - 48
            elif c == '[':
                stack.append((cur, num))
                cur = []
                num = 0
            elif c == ']':
                prev, cnt = stack.pop()
                cur = prev + cur * cnt
            else:
                cur.append(c)

        return ''.join(cur)