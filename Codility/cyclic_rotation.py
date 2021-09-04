# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, K):
    # write your code in Python 3.6
    if len(A) == 0:
    	return A
    for i in range(K):
        prev = A[-1]
        for j in range(0, len(A)):
            curr = A[j]
            A[j] = prev
            prev = curr
    return A