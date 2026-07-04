from collections import defaultdict, deque

class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        graph = defaultdict(list)

        for (a, b), v in zip(equations, values):
            graph[a].append((b, v))
            graph[b].append((a, 1.0 / v))

        ans = []

        for src, dst in queries:
            if src not in graph or dst not in graph:
                ans.append(-1.0)
                continue

            if src == dst:
                ans.append(1.0)
                continue

            q = deque([(src, 1.0)])
            vis = {src}
            found = -1.0

            while q:
                node, val = q.popleft()

                if node == dst:
                    found = val
                    break

                for nxt, w in graph[node]:
                    if nxt not in vis:
                        vis.add(nxt)
                        q.append((nxt, val * w))

            ans.append(found)

        return ans