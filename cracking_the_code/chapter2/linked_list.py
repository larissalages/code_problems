class Node:
    value = None
    next = None

    def __init__(self, v):
        self.value = v
        self.next = None


class LinkedList:
    head = None

    def __init__(self, lst=None):
        if isinstance(lst, list):
            self.list_to_linkedlist(lst)

    def __eq__(self, other):
        if not isinstance(other, LinkedList):
            # don't attempt to compare against unrelated types
            return False
        if self.length() != other.length():
            return False
        n = self.head
        m = other.head
        while n:
            if n.value != m.value:
                return False
            n = n.next
            m = m.next
        return True

    def length(self):
        n = self.head
        count = 0
        while n:
            count += 1
            n = n.next

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
            #item = str(item)
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
