import logging
from stack import *


class StackwithMin(Stack):
    def __init__(self):
        super().__init__()
        self.stack_min = Stack()

    def min(self):
        if self.stack_min.isEmpty():
            logging.warning('Stack Min is empty')
            return float('inf')
        return self.stack_min.peek()

    def push(self, value):
        if value < self.min():
            self.stack_min.push(value)
        super().push(value)

    def pop(self):
        value = super().pop()
        if value == self.min():
            self.stack_min.pop()
        return value

    def print_min(self):
        return print(self.min())


if __name__ == '__main__':
    stack_with_min = StackwithMin()
    print('pushes')
    stack_with_min.push(10)
    stack_with_min.print_min()
    stack_with_min.push(20)
    stack_with_min.print_min()
    stack_with_min.push(5)
    stack_with_min.print_min()
    stack_with_min.push(12)
    stack_with_min.print_min()
    print('pops')
    stack_with_min.pop()
    stack_with_min.print_min()
    stack_with_min.pop()
    stack_with_min.print_min()
