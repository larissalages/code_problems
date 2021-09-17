def solution(A):
    total = sum(A)
    m = float('inf')
    left_sum = 0

    for n in A[:-1]:
        left_sum += n
        v = abs(total - 2*left_sum)
        if v < m:
            m = v
    return m

