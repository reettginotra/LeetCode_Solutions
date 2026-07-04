class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)

        def count(x):
            i, j = n - 1, 0
            cnt = 0

            while i >= 0 and j < n:
                if matrix[i][j] <= x:
                    cnt += i + 1
                    j += 1
                else:
                    i -= 1

            return cnt

        left, right = matrix[0][0], matrix[-1][-1]

        while left < right:
            mid = (left + right) // 2

            if count(mid) < k:
                left = mid + 1
            else:
                right = mid

        return left