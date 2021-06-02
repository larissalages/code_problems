from stack import Stack


class MyQueue:
    def __init__(self):
        self.stk_newest = Stack()
        self.stk_oldest = Stack()

    def add(self, value):
        self.stk_newest.push(value)

    def shiftStack(self):
        if self.stk_oldest.isEmpty():
            while not self.stk_newest.isEmpty():
                self.stk_oldest.push(self.stk_newest.pop())

    def remove(self):
        self.shiftStack()
        return self.stk_oldest.pop()

    def peek(self):
        self.shiftStack()
        return self.stk_oldest.peek()


def main():
    q = MyQueue()
    q.add(1)
    q.add(2)
    q.add(3)
    print(q.remove())
    q.add(4)
    q.add(5)
    print(q.remove())
    print(q.remove())
    print(q.remove())


if __name__ == '__main__':
    main()
