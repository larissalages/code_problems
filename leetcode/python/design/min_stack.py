class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []

    def push(self, val: int) -> None:
        curr_min = self.getMin()
        if curr_min is None or val < curr_min:
            curr_min = val
        self.arr.append((val, curr_min))

    def pop(self) -> None:
        if len(self.arr) != 0:
            self.arr.pop()

    def top(self) -> int:
        if len(self.arr) > 0:
            return self.arr[-1][0]
        else:
            return None

    def getMin(self) -> int:
        if len(self.arr) > 0:
            return self.arr[-1][1]
        else:
            return None


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(2147483646)
obj.push(2147483646)
obj.push(2147483647)
print(obj.top())
obj.pop()
print(obj.getMin())
obj.pop()
print(obj.getMin())
obj.pop()
obj.push(2147483647)
print(obj.top())
print(obj.getMin())
obj.push(-2147483648)
print(obj.top())
print(obj.getMin())
obj.pop()
print(obj.getMin())

