class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#leetcode sol starts from here
class Solution(object):
    def removeElements(self, head, val):
        dummy = ListNode(0, head)
        curr = dummy

        while curr.next:
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next

        return dummy.next