ASCI_TABLE_SIZE = 256


class Node:
    value = None
    next = None

    def __init__(self, v):
        self.value = v
        self.next = None


class LinkedList:
    head = None

    def add(self, v):
        new = Node(v)
        if not self.head:
            self.head = new
            return
        p = self.head
        while p.next:
            p = p.next
        p.next = new

    def list_to_linkedlist(self, lst):
        for item in lst:
            item = str(item)
            self.add(item)

    def print(self):
        p = self.head
        str_lst = ''
        if not p:
            print('[]')
        while p:
            str_lst += '{}->'.format(p.value)
            p = p.next
        print(str_lst)


def remove_dups(l):
    seen = []
    for i in range(ASCI_TABLE_SIZE):
        seen.append(False)
    p = l.head
    # Zero or one node
    if not p or (p and not p.next):
        return l
    while p:
        seen[ord(p.value)] = True
        if p.next:
            if seen[ord(p.next.value)] is True:
                p.next = p.next.next
                while p.next and p.value == p.next.value:
                    p.next = p.next.next
            else:
                seen[ord(p.next.value)] = True
        p = p.next


if __name__ == '__main__':
    # create a list
    l = LinkedList()
    #l.list_to_linkedlist(['a', 'b', 'c', 'b', 'd'])
    l.list_to_linkedlist([1, 2, 1, 2, 3])
    #l.list_to_linkedlist([2, 2, 2, 2, 2])
    #l.list_to_linkedlist([])
    l.print()
    remove_dups(l)
    l.print()



