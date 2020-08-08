# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
	def bstToGst(self, root: TreeNode) -> TreeNode:
		def sum_tree(node, sum_aux):
			if not node:
				return None;
			if node.right:
				sum_aux, _ = sum_tree(node.right, sum_aux)

			sum_aux = sum_aux + node.val

			if node.left:
				sum_aux, _ = sum_tree(node.left, sum_aux)

			node.val = sum_aux
			return sum_aux, node

		_, new_tree = sum_tree(root, 0)
		return new_tree

