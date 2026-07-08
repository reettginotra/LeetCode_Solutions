class Node(object):
    __slots__ = ("key", "val", "freq", "prev", "next")

    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None


class DLinkedList(object):
    __slots__ = ("head", "tail", "size")

    def __init__(self):
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def add(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node
        self.size += 1

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1

    def pop(self):
        if self.size == 0:
            return None
        node = self.tail.prev
        self.remove(node)
        return node


class LFUCache(object):

    def __init__(self, capacity):
        self.cap = capacity
        self.minFreq = 0
        self.nodes = {}
        self.freqs = {}

    def _update(self, node):
        f = node.freq
        lst = self.freqs[f]
        lst.remove(node)

        if f == self.minFreq and lst.size == 0:
            self.minFreq += 1

        node.freq += 1

        if node.freq not in self.freqs:
            self.freqs[node.freq] = DLinkedList()

        self.freqs[node.freq].add(node)

    def get(self, key):
        node = self.nodes.get(key)

        if node is None:
            return -1

        self._update(node)
        return node.val

    def put(self, key, value):
        if self.cap == 0:
            return

        node = self.nodes.get(key)

        if node:
            node.val = value
            self._update(node)
            return

        if len(self.nodes) == self.cap:
            node = self.freqs[self.minFreq].pop()
            del self.nodes[node.key]

        node = Node(key, value)
        self.nodes[key] = node

        if 1 not in self.freqs:
            self.freqs[1] = DLinkedList()

        self.freqs[1].add(node)
        self.minFreq = 1