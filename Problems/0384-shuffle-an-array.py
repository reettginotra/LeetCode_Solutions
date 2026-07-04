import random

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.original = nums[:]

    def reset(self):
        """
        :rtype: List[int]
        """
        return self.original

    def shuffle(self):
        """
        :rtype: List[int]
        """
        arr = self.original[:]

        for i in range(len(arr) - 1, 0, -1):
            j = random.randint(0, i)
            arr[i], arr[j] = arr[j], arr[i]

        return arr