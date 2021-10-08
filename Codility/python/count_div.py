def solution(A, B, K):
    count = B//K - A//K
    if A%K==0:
        count+= 1
    return count
