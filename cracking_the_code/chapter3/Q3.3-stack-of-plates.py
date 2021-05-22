import logging
from stack import Stack


class SetOfStacks:
    lst_stacks = []

    def __init__(self, capacity):
        self.capacity = capacity
        self.lst_stacks.append(Stack())
        self.last_stack_size = 0

    def push(self, value):
        last_stack = self.lst_stacks[-1]
        if self.last_stack_size < self.capacity:
            last_stack.push(value)
            self.last_stack_size += 1
        else:
            new_stk = Stack()
            new_stk.push(value)
            self.lst_stacks.append(new_stk)
            self.last_stack_size = 1

    def pop(self):
        last_stack = self.lst_stacks[-1]
        value = last_stack.pop()
        if last_stack.isEmpty():
            self.lst_stacks.pop(-1)  # rm empty stack
            self.last_stack_size = self.capacity
        return value


def main():
    print("jasjdlaksd")


if __name__ == '__main__':
    main()
