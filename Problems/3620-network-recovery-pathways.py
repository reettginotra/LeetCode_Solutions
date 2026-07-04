from collections import deque

class Solution(object):
    def findMaxPathScore(self, edges, online, k):
        """
        :type edges: List[List[int]]
        :type online: List[bool]
        :type k: int
        :rtype: int
        """
        n = len(online)
        if n == 0:
            return -1

        adj = [[] for _ in range(n)]
        indeg = [0] * n
        max_cost = 0

        for u, v, c in edges:
            adj[u].append((v, c))
            indeg[v] += 1
            if c > max_cost:
                max_cost = c

        # Topological order
        q = deque()
        for i in range(n):
            if indeg[i] == 0:
                q.append(i)

        topo = []
        while q:
            u = q.popleft()
            topo.append(u)
            for v, _ in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        INF = 10 ** 30

        def feasible(threshold):
            dist = [INF] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == INF:
                    continue
                if u != 0 and u != n - 1 and not online[u]:
                    continue

                for v, c in adj[u]:
                    if c < threshold:
                        continue
                    if v != n - 1 and not online[v]:
                        continue
                    nd = dist[u] + c
                    if nd < dist[v]:
                        dist[v] = nd

            return dist[n - 1] <= k

        if not feasible(0):
            return -1

        lo, hi = 0, max_cost
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if feasible(mid):
                lo = mid
            else:
                hi = mid - 1

        return lo