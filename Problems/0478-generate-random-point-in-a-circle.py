import random
import math

class Solution(object):

    def __init__(self, radius, x_center, y_center):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self):
        theta = random.random() * 2.0 * math.pi
        dist = self.r * math.sqrt(random.random())

        return [
            self.x + dist * math.cos(theta),
            self.y + dist * math.sin(theta)
        ]