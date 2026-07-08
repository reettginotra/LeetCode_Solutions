class Solution(object):
    def islandPerimeter(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        ans = 0

        for i in range(rows):
            row = grid[i]
            for j in range(cols):
                if row[j]:
                    ans += 4
                    if i and grid[i - 1][j]:
                        ans -= 2
                    if j and row[j - 1]:
                        ans -= 2

        return ans