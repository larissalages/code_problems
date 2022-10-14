import logging
from linked_list import *


# We can simply copy the value of next node to the current node and delete next node
def delete_middle_node(node):
    if not node:
        return
    node.value = node.next.value
    node.next = node.next.next


def main():
    # build a list
    lst = LinkedList(['a', 'b', 'c', 'd', 'e', 'f'])
    p = lst.head()
    while p.value != 'c':
        p = p.next
    delete_middle_node(p)
    lst.print()


if __name__ == '__main__':
    main()
