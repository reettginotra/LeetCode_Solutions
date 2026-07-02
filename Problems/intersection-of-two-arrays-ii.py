class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        freq = {}

        for num in nums1:
            freq[num] = freq.get(num, 0) + 1

        ans = []

        for num in nums2:
            if freq.get(num, 0) > 0:
                ans.append(num)
                freq[num] -= 1

        return ans