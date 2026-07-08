class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        mp = {}
        get = mp.get

        for a in nums1:
            for b in nums2:
                s = a + b
                mp[s] = get(s, 0) + 1

        ans = 0
        get = mp.get

        for c in nums3:
            for d in nums4:
                ans += get(-(c + d), 0)

        return ans