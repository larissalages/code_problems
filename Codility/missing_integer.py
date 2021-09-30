def solution(A):
    if len(A) == 1:
        return A[0] + 1
    A = sorted(A)
    A = [num if num > 0 else 0 for num in A]
    for i in range(len(A)):
        if i+1<len(A) and A[i] > 0:
            if A[i+1] != A[i]+1 and A[i+1] != A[i]:
                return A[i] +1

    return A[-1] + 1
