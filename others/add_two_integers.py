"""
Problem Statement
Given the head pointers of two linked lists where each linked list represents an integer number (each node is a digit), 
add them and return the resulting linked list. Here, the first node in a list represents the least significant digit.
"""
class Node:
	def __init__(self, value):
		self.value = value
		self.next = None

def sum_lists(l1, l2):
	c = 0
	l3 = None
	while l1 or l2:
		v1 = 0
		v2 = 0
		if l1:
			v1 = l1.value
			l1 = l1.next
		if l2:
			v2 = l2.value
			l2 = l2.next
		r = v1 + v2 + c
		c = r // 10
		d = r % 10

		if not l3:
			l3 = Node(d)
			p3 = l3
		else:
			p3.next = Node(d)
			p3 = p3.next

	return l3

def print_list(l):
	while l:
		print("{}->".format(l.value), end = '')
		l = l.next

def print_number(l):
	stack = []
	while l:
		stack.append(l.value)
		l = l.next
	while len(stack) > 0:
		v = stack.pop()
		print("{}".format(v), end = '')

def create_linked_list(list_numbers):
	l = None
	for n in list_numbers:
		if not l:
			l = Node(n)
			p = l
		else:
			p.next = Node(n)
			p = p.next
	return l 

first = create_linked_list([1, 2, 3]) #321
second = create_linked_list([1, 2]) #21
print("Sum:", end='')
r = sum_lists(first, second)
print_number(r)
print()
