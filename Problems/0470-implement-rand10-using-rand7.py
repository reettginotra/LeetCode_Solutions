import random
def rand7():
    return random.randint(1, 7)

#leetcode sol starts from here
class Solution(object):
    def rand10(self):
        while True:
            num = (rand7() - 1) * 7 + rand7()
            if num <= 40:
                return (num - 1) % 10 + 1