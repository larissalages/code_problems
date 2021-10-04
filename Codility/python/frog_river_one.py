def solution(X, A):
	hash_t = {}
	for i in range(1, X+1):
		hash_t[i] = 1	

    for i in range(len(A)):
    	if hash_t.get(A[i]):
    		del hash_t[A[i]]
    	if not hash_t:
    		return i
    return -1
