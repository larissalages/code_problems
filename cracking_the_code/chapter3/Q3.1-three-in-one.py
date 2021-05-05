import logging


class StackInfo:
    def __init__(self, start, capacity, array):
        self.start = start
        self.capacity = capacity
        self.end = capacity - 1
        self.array = array
        self.size = 0
        self.last_index = self.start

    def is_withing_stack_capacity(self, index):
        if index < 0 or index >= len(self.array):
            return False
        return self.start <= index < self.end

    def last_capacity_index(self):
        return self.end

    def last_element_index(self):
        return self.last_index

    def is_full(self):
        return self.size == self.capacity

    def is_empty(self):
        return self.size == 0


class MultiStack:
    def __init__(self, nstacks, stack_size):
        self.array = [0]*(nstacks*stack_size)
        self.info = []  # list of StackInfo
        for i in range(nstacks):
            self.info.append(StackInfo(i*stack_size, stack_size))

    def all_stacks_are_full(self):
        number_of_items = 0
        for i in range(len(self.info)):
            number_of_items += self.info[i].size
        return number_of_items == len(self.array)

    def shift(self, stack_number):
        logging.info("Shifiting stack {}".format(str(stack_number+1)))
        return

    def expand(self, stack_number):
        self.shift(stack_number % len(self.info))

    def push(self, stack_number, value):
        array_stack_number = stack_number - 1
        stack = self.info[array_stack_number]
        if self.all_stacks_are_full:
            logging.error('Array is full!! Cannot push anything else')
        if stack.is_full():
            self.expand(array_stack_number)  # implement function
        stack.size += 1
        self.array[stack.last_element_index()] = value


