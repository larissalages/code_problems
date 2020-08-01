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

def tree2list(sorted_list, node):
	if node.left:
		tree2list(sorted_list, node.left)
	sorted_list.append(node)
	if node.right:
		tree2list(sorted_list, node.right)
	if node.left is None or node.right is None:
		return sorted_list

def insert_balance_tree(sorted_list, tree):
	mid = len(sorted_list)/2
	tree.insert(sorted_list[insert])
	insert_balance_tree(sorted_list[0:mid], tree)
	insert_balance_tree(sorted_list[mid+1:len(sorted_list)], tree)


class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
    # TODO: call tree2list and insert_balance_tree


            
        