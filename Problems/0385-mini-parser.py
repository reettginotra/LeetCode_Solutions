# Mock NestedInteger for local testing

class NestedInteger(object):
    def __init__(self, value=None):
        if value is None:
            self.value = None
            self.list = []
        else:
            self.value = value
            self.list = None

    def isInteger(self):
        return self.value is not None

    def add(self, elem):
        if self.list is None:
            self.list = []
            self.value = None
        self.list.append(elem)

    def setInteger(self, value):
        self.value = value
        self.list = None

    def getInteger(self):
        return self.value

    def getList(self):
        return self.list


# LeetCode solution starts from here

class Solution(object):
    def deserialize(self, s):
        if s[0] != '[':
            return NestedInteger(int(s))

        stack = []
        num = 0
        sign = 1
        has_num = False

        for c in s:
            if c == '[':
                stack.append(NestedInteger())
            elif c == '-':
                sign = -1
            elif '0' <= c <= '9':
                num = num * 10 + ord(c) - 48
                has_num = True
            elif c == ',' or c == ']':
                if has_num:
                    stack[-1].add(NestedInteger(sign * num))
                    num = 0
                    sign = 1
                    has_num = False
                if c == ']' and len(stack) > 1:
                    cur = stack.pop()
                    stack[-1].add(cur)

        return stack[0]