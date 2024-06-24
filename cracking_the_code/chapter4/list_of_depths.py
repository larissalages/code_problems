import collections


def dfs_tree2list(node, lvl, arr):
    if node is None:
        return
    if lvl >= len(arr):
        linked_lst = collections.deque()  # linkedlist
        arr.append(linked_lst)
    arr[lvl].append(node.value)
    dfs_tree2list(node.left, lvl+1, arr)
    dfs_tree2list(node.right, lvl+1, arr)


def dft_tree2list(node, arr):
    current = collections.deque()  # linkedlist
    current.append(node)

    while current:  # while not empty
        arr.append(current)
        parents = current
        for parent in parents:
            if parent.left:
                current.append(parent.left)
            if parent.right:
                current.append(parent.right)


def main():
    # TODO: Create Tree
    dfs_tree2list([], 0, [])


if __name__ == "__main__":
    main()

