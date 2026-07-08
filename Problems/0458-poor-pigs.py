class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        if buckets == 1:
            return 0

        states = minutesToTest // minutesToDie + 1
        pigs = 0
        power = 1

        while power < buckets:
            pigs += 1
            power *= states

        return pigs