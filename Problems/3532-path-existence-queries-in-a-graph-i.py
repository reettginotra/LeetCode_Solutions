class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        parent = list(range(n))

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for i in range(1, n):
            if nums[i] - nums[i - 1] <= maxDiff:
                a = find(i)
                b = find(i - 1)
                if a != b:
                    parent[a] = b

        ans = []
        append = ans.append

        for u, v in queries:
            append(find(u) == find(v))

        return ans