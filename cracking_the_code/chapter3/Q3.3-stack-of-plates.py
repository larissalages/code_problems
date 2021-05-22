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
        self.last_stack_size -= 1
        if last_stack.isEmpty():
            self.lst_stacks.pop(-1)  # rm empty stack
            self.last_stack_size = self.capacity
        return value

    def print_stacks(self):
        print('Printing Stacks')
        for stk in self.lst_stacks:
            stk.print()
            print('----------')
        print('Done printing stacks')


def main():
    # insert a bunch of items
    weird_stack = SetOfStacks(3)
    weird_stack.push('a')
    weird_stack.push('b')
    weird_stack.push('c')
    weird_stack.push('d')
    weird_stack.push('e')
    weird_stack.push('f')
    weird_stack.push('g')
    weird_stack.push('h')
    weird_stack.print_stacks()

    # pop them and look how the stacks are
    weird_stack.pop()
    weird_stack.pop()
    weird_stack.pop()
    weird_stack.print_stacks()

    # insert more items 
    weird_stack.push('i')
    weird_stack.push('j')
    weird_stack.push('k')
    weird_stack.print_stacks()


if __name__ == '__main__':
    main()
