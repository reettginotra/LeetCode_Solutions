class Solution(object):
    def makesquare(self, matchsticks):
        if len(matchsticks) < 4:
            return False

        total = sum(matchsticks)

        if total & 3:
            return False

        side = total >> 2
        matchsticks.sort(reverse=True)

        if matchsticks[0] > side:
            return False

        sides = [0, 0, 0, 0]

        def dfs(idx):
            if idx == len(matchsticks):
                return True

            x = matchsticks[idx]

            for i in range(4):
                if sides[i] + x > side:
                    continue

                if i and sides[i] == sides[i - 1]:
                    continue

                sides[i] += x

                if dfs(idx + 1):
                    return True

                sides[i] -= x

                if sides[i] == 0:
                    break

            return False

        return dfs(0)