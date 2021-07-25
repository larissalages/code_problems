class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []
        self.min_arr = []

    def push(self, val: int) -> None:
        if len(self.min_arr) == 0 or self.getMin() >= val:
            self.min_arr.append(val)

        self.arr.append(val)

    def pop(self) -> None:
        if len(self.arr) == 0:
            return
        v = self.arr.pop()
        if v == self.getMin():
            self.min_arr.pop()

    def top(self) -> int:
        if len(self.arr) > 0:
            return self.arr[-1]
        else:
            print("Empty Stack!")

    def getMin(self) -> int:
        if len(self.min_arr) > 0:
            return self.min_arr[-1]
        else:
            return pow(2, 31)


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

