import random
from collections import defaultdict

class RandomizedCollection(object):

    def __init__(self):
        self.arr = []
        self.pos = defaultdict(set)

    def insert(self, val):
        present = val in self.pos

        self.arr.append(val)
        self.pos[val].add(len(self.arr) - 1)

        return not present

    def remove(self, val):
        if val not in self.pos:
            return False

        idx = self.pos[val].pop()
        last = self.arr[-1]

        if idx != len(self.arr) - 1:
            self.arr[idx] = last
            self.pos[last].remove(len(self.arr) - 1)
            self.pos[last].add(idx)

        self.arr.pop()

        if not self.pos[val]:
            del self.pos[val]

        return True

    def getRandom(self):
        return random.choice(self.arr)