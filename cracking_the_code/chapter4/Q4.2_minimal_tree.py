################################################(Way 1)#############################################################
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
			self.right.printTree()


def createMinTree(tree, list_num):
	mid = len(list_num)//2
	tree.insertTree(list_num[mid])
	if mid == 0:
		return
	createMinTree(tree, list_num[0:mid])
	if mid == len(list_num)-1:
		return
	createMinTree(tree, list_num[mid+1:len(list_num)])

################################################Another way to do it (Way 2)###########################################
class BinaryTree:
	def __init__(self, content, left=None, right=None):
		self.content = content
		self.left = left
		self.right = right

	def __str__(self):
		return "( " + str(self.content) + " ( " + str(self.left) + " | " + str(self.right) + "))"


def int_array_to_binary_search_tree(intarray):
	# use the middle of the array to divide it. this ensures minimal height.
	if len(intarray) == 0:
		return None
	if len(intarray) == 1:
		return BinaryTree(intarray[0])
	cut = len(intarray) // 2
	return BinaryTree(intarray[cut], int_array_to_binary_search_tree(intarray[0:cut]),  int_array_to_binary_search_tree(intarray[cut+1:]))


def main():
	# Way 1
	# arr = [1, 3, 5, 6, 7, 8]
	# tree = Node()
	# createMinTree(tree, arr)
	# tree.printTree()

	# Way 2
	arr = [1, 3, 5, 6, 7, 8]
	print(str(int_array_to_binary_search_tree(arr)))


if __name__ == "__main__":
	main()
