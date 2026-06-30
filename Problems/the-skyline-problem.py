from typing import List
import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []

        # Create start and end events
        for left, right, height in buildings:
            events.append((left, -height, right))
            events.append((right, 0, 0))

        events.sort()

        res = []
        heap = [(0, float('inf'))]   # (-height, right)

        for x, negH, right in events:

            while heap and heap[0][1] <= x:
                heapq.heappop(heap)

            if negH:
                heapq.heappush(heap, (negH, right))

            currHeight = -heap[0][0]

            if not res or res[-1][1] != currHeight:
                res.append([x, currHeight])

        return res