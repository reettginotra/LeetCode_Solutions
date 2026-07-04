import random

class Solution(object):

    def __init__(self, head):
        """
        :type head: Optional[ListNode]
        """
        self.head = head

    def getRandom(self):
        """
        :rtype: int
        """
        ans = self.head.val
        node = self.head.next
        i = 2

        while node:
            if random.randrange(i) == 0:
                ans = node.val
            node = node.next
            i += 1

        return ans