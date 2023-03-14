"""
Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given value. 
Return true if the sum exists and return false if it does not.
"""

def sum_of_two_exist(a, value):
	existing_numbers = set()
	for n in a:
		if (value - n) in existing_numbers:
			return True
		existing_numbers.add(n)
	return False

a = [5,7,1,2,8,4,3]
test = [10,3,20,1,2,7]

for v in test:
	equal = sum_of_two_exist(a, v)
	if equal:
		print("Value {} exist on sum of two ints in array {}".format(v, a))
	else:
		print("Value {} DOES NOT exist on sum of two ints in array {}".format(v, a))
