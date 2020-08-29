
class Node:
	def __init__(self, data=None):
		self.data = data
		self.left = None
		self.right = None

	def insertTree(self, data):
		if self.data:
			if data < self.data:
				if self.left:
					self.left.insertTree(data)
				else:
					self.left = Node(data)
			else:
				if self.right:
					self.right.insertTree(data)
				else:
					self.right = Node(data)
		else:
			self.data = data

	def printTree(self):
		if self.left:
			self.left.printTree()
		print(self.data)
		if self.right:
			self.right.printTree


def createMinTree(tree, list_num):
	mid = len(list_num)//2
	tree.insertTree(list_num[mid])
	if mid == 0:
		return
	createMinTree(tree, list_num[0:mid])
	if mid == len(list_num)-1:
		return
	createMinTree(tree, list_num[mid+1:len(list_num)])


def main():
	print("main")
	arr = [1, 3, 5, 6, 7, 8]
	tree = Node()
	createMinTree(tree, arr)
	tree.printTree()
	print("end")


if __name__ == "__main__":
    main()

