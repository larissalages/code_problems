import logging


class Node:
    value = None
    next = None

    def __init__(self, value):
        self.value = value


class Stack:
    def __init__(self):
        self.top = None

    def push(self, value):
        temp = Node(value)
        temp.next = self.top
        self.top = temp

    def pop(self):
        if not self.top:
            logging.warning('Stack is empty!')
            return None
        value = self.top.value
        self.top = self.top.next
        return value

    def peek(self):
        return self.top

    def isEmpty(self):
        if not self.top:
            return True
        return False

    def print(self):
        tmp_stack = Stack()
        while not self.isEmpty():
            item = self.pop()
            print(str(item))
            tmp_stack.push(item)
        # put back items in stack
        while not tmp_stack.isEmpty():
            item = tmp_stack.pop()
            self.push(item)


if __name__ == '__main__':
    mystack = Stack()
    mystack.push(5)
    mystack.push(6)
    mystack.push(7)
    mystack.push(8)
    mystack.push(2)
    mystack.print()

