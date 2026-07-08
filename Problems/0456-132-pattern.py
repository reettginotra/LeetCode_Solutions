class Solution:
    def find132pattern(self, nums):
        stack = []
        third = float('-inf')

        push = stack.append
        pop = stack.pop

        for i in range(len(nums) - 1, -1, -1):
            x = nums[i]

            if x < third:
                return True

            while stack and x > stack[-1]:
                third = pop()

            push(x)

        return False