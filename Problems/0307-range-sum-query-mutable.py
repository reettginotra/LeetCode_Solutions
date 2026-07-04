class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.n = len(nums)
        self.tree = [0] * (4 * self.n)
        self.build(nums, 1, 0, self.n - 1)

    def build(self, nums, node, l, r):
        if l == r:
            self.tree[node] = nums[l]
            return

        mid = (l + r) // 2
        self.build(nums, 2 * node, l, mid)
        self.build(nums, 2 * node + 1, mid + 1, r)
        self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def updateHelper(self, node, l, r, idx, val):
        if l == r:
            self.tree[node] = val
            return

        mid = (l + r) // 2
        if idx <= mid:
            self.updateHelper(2 * node, l, mid, idx, val)
        else:
            self.updateHelper(2 * node + 1, mid + 1, r, idx, val)

        self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def query(self, node, l, r, ql, qr):
        if ql <= l and r <= qr:
            return self.tree[node]

        if r < ql or l > qr:
            return 0

        mid = (l + r) // 2
        return (self.query(2 * node, l, mid, ql, qr) +
                self.query(2 * node + 1, mid + 1, r, ql, qr))

    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self.updateHelper(1, 0, self.n - 1, index, val)

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return self.query(1, 0, self.n - 1, left, right)
