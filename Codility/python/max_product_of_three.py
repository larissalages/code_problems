def solution(A):
    A.sort()
    scenario1 = A[0] * A[1] * A[-1]
    scenario2 = A[-1] * A[-2] * A[-3]
    
    return scenario1 if (scenario1 > scenario2) else scenario2

