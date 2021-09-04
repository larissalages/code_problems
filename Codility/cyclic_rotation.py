
# Frist Solution
def solution(A, K):
    if len(A) == 0:
    	return A
    for i in range(K):
        prev = A[-1]
        for j in range(0, len(A)):
            curr = A[j]
            A[j] = prev
            prev = curr
    return A

# Second Solution
def solution(A, K):
    if len(A) == 0:
    	return A
    K = K % len(A)
    return A[-K:] + A[:-K]
