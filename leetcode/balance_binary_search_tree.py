# Given a binary search tree, return a balanced binary search tree with the same node values.

# A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

# If there is more than one answer, return any of them.

# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

	def insert(self, data):
		if self.val:
			if data < self.val:
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
			self.val = data

def tree2list(sorted_list, node):
	if node.left:
		sorted_list.append(tree2list(sorted_list, node.left))
	sorted_list.append(node)
	if node.right:
		sorted_list.append(tree2list(sorted_list, node.right))
	if node.left is None or node.right is None:
		return node.val

def insert_balance_tree(sorted_list, tree):
	if not sorted_list:
		return 
	if isinstance(sorted_list, list): 
		mid = len(sorted_list)//2
		tree.insert(sorted_list[mid])
		insert_balance_tree(sorted_list[0:mid], tree)
		insert_balance_tree(sorted_list[mid+1:len(sorted_list)], tree)

class Solution2:
	def balanceBST(self, root: TreeNode) -> TreeNode:
		list_tree = []
		list_tree = tree2list(list_tree, root)
		new_root = TreeNode()
		new_root.val = None
		insert_balance_tree(list_tree, new_root)
		return new_root

# Right Solution		
class Solution:
	def balanceBST(self, root: TreeNode) -> TreeNode:
		v = []
		def dfs(node):
			if node:
				dfs(node.left)
				v.append(node.val)
				dfs(node.right)
		dfs(root)

		def bst(v):
			if not v:
				return None
			mid = len(v)//2
			root = TreeNode(v[mid])
			root.left = bst(v[:mid])
			root.right = bst(v[mid+1:])
			return root

		return bst(v)



			
		