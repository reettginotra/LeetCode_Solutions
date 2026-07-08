class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        if desiredTotal <= 0:
            return True

        if (maxChoosableInteger * (maxChoosableInteger + 1)) // 2 < desiredTotal:
            return False

        memo = {}

        def dfs(mask, remain):
            if mask in memo:
                return memo[mask]

            for i in range(maxChoosableInteger):
                bit = 1 << i

                if mask & bit:
                    continue

                if i + 1 >= remain or not dfs(mask | bit, remain - i - 1):
                    memo[mask] = True
                    return True

            memo[mask] = False
            return False

        return dfs(0, desiredTotal)