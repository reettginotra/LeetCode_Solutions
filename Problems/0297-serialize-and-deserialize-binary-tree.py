class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        vals = []

        def dfs(node):
            if not node:
                vals.append("null")
                return

            vals.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(vals)

    def deserialize(self, data):
        vals = data.split(",")
        self.index = 0

        def dfs():
            if vals[self.index] == "null":
                self.index += 1
                return None

            node = TreeNode(int(vals[self.index]))
            self.index += 1

            node.left = dfs()
            node.right = dfs()

            return node

        return dfs()
