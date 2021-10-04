def solution(A):
	m = []
	n = []
	count_t = 0
	for i in range(len(A)):
		if A[i] == 0:
			m.append(i)
		else:
			n.append(i)
	for i in m:
		for j in n:
			if j > i:
				count_t += 1
				if count_t  > 1000000000:
					return -1
	return count_t
