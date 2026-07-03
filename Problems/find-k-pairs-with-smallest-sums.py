import heapq

# LeetCode solution starts from here
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        if not nums1 or not nums2 or k == 0:
            return []

        heap = []

        for i in range(min(len(nums1), k)):
            heapq.heappush(heap, (nums1[i] + nums2[0], i, 0))

        ans = []

        while heap and k:
            _, i, j = heapq.heappop(heap)
            ans.append([nums1[i], nums2[j]])
            k -= 1

            if j + 1 < len(nums2):
                heapq.heappush(heap, (nums1[i] + nums2[j + 1], i, j + 1))

        return ans