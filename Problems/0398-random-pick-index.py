import random
from collections import defaultdict

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.pos = defaultdict(list)
        for i, x in enumerate(nums):
            self.pos[x].append(i)

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        return random.choice(self.pos[target])