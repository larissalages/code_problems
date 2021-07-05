class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class MinimalTree:
    def __init__(self, array):
        self.root = self.createMinimalBST(array)

    def createMinimalBST(self, array):
        if len(array) <= 0:
            return None
        mid_idx = len(array)//2
        node = Node(array[mid_idx])
        node.left = self.createMinimalBST(array[0:mid_idx])
        node.right = self.createMinimalBST(array[mid_idx+1:len(array)])
        return node


def print_tree(node):
    if node:
        print_tree(node.left)
        print(node.value)
        print_tree(node.right)


def main():
    tree = MinimalTree([5, 10, 15, 20, 30, 40])
    print_tree(tree.root)


if __name__ == "__main__":
    main()
