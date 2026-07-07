class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0] * 26

        for c in s:
            cnt[ord(c) - 97] += 1

        ans = [0] * 10

        ans[0] = cnt[25]
        ans[2] = cnt[22]
        ans[4] = cnt[20]
        ans[6] = cnt[23]
        ans[8] = cnt[6]

        ans[3] = cnt[7] - ans[8]
        ans[5] = cnt[5] - ans[4]
        ans[7] = cnt[18] - ans[6]
        ans[1] = cnt[14] - ans[0] - ans[2] - ans[4]
        ans[9] = cnt[8] - ans[5] - ans[6] - ans[8]

        res = []

        for i in range(10):
            if ans[i]:
                res.append(str(i) * ans[i])

        return ''.join(res)