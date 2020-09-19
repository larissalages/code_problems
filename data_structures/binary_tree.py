#!/bin/python3
import time
start = time.time()

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()

    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                    return
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                    return
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def search_value(self, data):
        if self.data == data:
            print("value {} is found".format(data))
            return
        elif data < self.data:
            if self.left:
                return self.left.search_value(data)
            else:
                print("value {} does not exist!".format(data))
                return
        else:
            if self.right:
                return self.right.search_value(data)
            else:
                print("value {} does not exist!".format(data))
                return


root = Node(12)
root.insert(6)
root.insert(14)
root.insert(3)
root.PrintTree()
root.search_value(18)

print('Execution time:', time.time()-start, 'seconds.')

 