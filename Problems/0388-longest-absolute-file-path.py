class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        depth_len = {0: 0}
        ans = 0

        for s in input.split('\n'):
            depth = s.count('\t')
            name = s[depth:]

            if '.' in name:
                ans = max(ans, depth_len[depth] + len(name))
            else:
                depth_len[depth + 1] = depth_len[depth] + len(name) + 1

        return ans