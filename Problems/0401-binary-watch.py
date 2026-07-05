class Solution(object):
    def readBinaryWatch(self, turnedOn):
        """
        :type turnedOn: int
        :rtype: List[str]
        """
        ans = []

        for h in range(12):
            hc = bin(h).count('1')
            for m in range(60):
                if hc + bin(m).count('1') == turnedOn:
                    ans.append("%d:%02d" % (h, m))

        return ans