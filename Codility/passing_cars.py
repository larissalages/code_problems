def solution(A):
	pairs = 0
	num_z = 0
	for i in range(len(A)):
		if A[i] == 0:
			num_z += 1
		else:
			pairs += num_z
			if pairs > 1000000000:
				return -1
	return pairs
