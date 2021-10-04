def solution(A):
	m = []
	n = []
	count = 0
	for i in range(len(A)):
		if A[i] == 0:
			m.append(i)
		else:
			n.append(i)
	for i in m:
		for j in n:
			if j > i:
				count += 1
				if count  > 1000000000:
					return -1
	return count
