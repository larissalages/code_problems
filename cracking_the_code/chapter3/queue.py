import logging


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Queue:
    def __init__(self):
        self.first = None
        self.last = None

    def add(self, value):
        tmp = Node(value)
        if self.last:
            self.last.next = tmp
        self.last = tmp
        if not self.first:
            self.first = tmp

    def remove(self):
        if not self.first:
            logging.warning('Queue is empty!')
            return
        value = self.first.value
        self.first = self.first.next
        return value

    def peek(self):
        if not self.first:
            logging.warning('Queue is empty!')
            return
        return self.first.value

    def isEmpty(self):
        return self.first is None

    def print(self):
        p = self.first
        while p:
            print(p.value)
            p = p.next


if __name__ == '__main__':
    q = Queue()
    print(q.isEmpty())
    q.add(1)
    q.add(2)
    q.add(3)
    q.add(4)
    q.add(5)
    print(q.isEmpty())
    print(q.peek())
    print('------')
    q.print()
    q.remove()
    print('------')
    q.print()
