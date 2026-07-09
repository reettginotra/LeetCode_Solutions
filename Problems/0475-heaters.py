class Solution(object):
    def findRadius(self, houses, heaters):
        houses.sort()
        heaters.sort()

        ans = 0
        j = 0
        m = len(heaters)

        for house in houses:
            while j + 1 < m and abs(heaters[j + 1] - house) <= abs(heaters[j] - house):
                j += 1

            d = abs(heaters[j] - house)
            if d > ans:
                ans = d

        return ans