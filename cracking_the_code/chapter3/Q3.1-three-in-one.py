import logging


class StackInfo:
    def __init__(self, start, capacity, array):
        self.start = start
        self.capacity = capacity
        self.end = capacity - 1
        self.array = array
        self.last_index = self.start

    def is_withing_stack_capacity(self, index):
        if index < 0 or index >= len(self.array):
            return False
        return self.start <= index < self.end

    def size(self):
        return self.last_index - self.start

    def last_capacity_index(self):
        return self.end

    def is_full(self):
        return self.last_index == self.capacity - 1

    def is_empty(self):
        return self.last_index == 0


class MultiStack:
    def __init__(self, nstacks, stack_size):
        self.array = [0]*(nstacks*stack_size)
        self.info = []  # list of StackInfo
        for i in range(nstacks):
            self.info.append(StackInfo(i*stack_size, stack_size))

    def all_stacks_are_full(self):
        number_of_items = 0
        for i in range(len(self.info)):
            number_of_items += self.info[i].size()
        return number_of_items == len(self.array)

    def adjust_last_index(self, stack_number):
        index = self.info[stack_number].last_index
        if index >= len(self.array):
            index = 0
        elif index < 0:
            index = len(self.array) - 1
        return index

    def shift(self, stack_number):
        logging.info("Shifiting stack {}".format(str(stack_number+1)))
        stack = self.info[stack_number]

        if stack.size() >= stack.capacity:
            nextStack = stack_number + 1
            self.shift(nextStack)
            stack.capacity += 1

        index = stack.last_capacity_index()
        while stack.is_withing_stack_capacity(index):
            self.array[index] = self.array[index-1]
            index = index - 1
        self.array[stack.start] = 0
        stack.start = stack.start + 1
        stack.last_index = stack.last_index + 1
        self.adjust_last_index(stack_number)
        stack.capacity -= 1

    def expand(self, stack_number):
        """ stack 0 -> shift(1)
            stack 1 -> shitf(2)
            stack 3 -> shift(0)
        """
        self.shift((stack_number+1) % len(self.info))
        self.info[stack_number].capacity += 1

    def push(self, stack_number, value):
        stack = self.info[stack_number]
        if self.all_stacks_are_full:
            logging.error('Array is full!! Cannot push anything else')
        if stack.is_full():
            self.expand(stack_number)  # implement function
        stack.last_index += 1
        self.adjust_last_index(stack_number)
        self.array[stack.last_index] = value

    def pop(self, stack_number):
        stack = self.info[stack_number]
        if stack.is_empty():
            logging.warning('Stack is empty!!')
            return
        value = self.array[stack.last_index]
        self.array[stack.last_index] = 0
        stack.last_index -= 1
        self.adjust_last_index(stack_number)
        return value

