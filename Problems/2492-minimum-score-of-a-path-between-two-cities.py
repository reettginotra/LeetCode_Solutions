from collections import defaultdict, deque

class Solution(object):
    def minScore(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        graph = defaultdict(list)

        for u, v, w in roads:
            graph[u].append((v, w))
            graph[v].append((u, w))

        ans = float('inf')
        vis = set()
        q = deque([1])
        vis.add(1)

        while q:
            u = q.popleft()

            for v, w in graph[u]:
                ans = min(ans, w)
                if v not in vis:
                    vis.add(v)
                    q.append(v)

        return ans