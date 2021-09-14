def solution(A):
    n = len(A) + 1
    return int(n*(n+1)/2 - sum(A))
