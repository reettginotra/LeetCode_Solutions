class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        corners = set()
        area = 0

        x1 = y1 = float('inf')
        x2 = y2 = float('-inf')

        for x, y, a, b in rectangles:
            x1 = min(x1, x)
            y1 = min(y1, y)
            x2 = max(x2, a)
            y2 = max(y2, b)

            area += (a - x) * (b - y)

            for p in ((x, y), (x, b), (a, y), (a, b)):
                if p in corners:
                    corners.remove(p)
                else:
                    corners.add(p)

        if area != (x2 - x1) * (y2 - y1):
            return False

        return corners == {(x1, y1), (x1, y2), (x2, y1), (x2, y2)}