def solution(A):
	dict_ = {}
	for elem in A:
		dict_[elem] = 1
	for i in range(1, len(A)+1):
		if not dict_.get(i):
			return i
	return len(A) + 1

