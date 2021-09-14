def solution(A):
    total = sum(A)
    m = float('inf')
    left_sum = 0

    for n in A:
        left_sum += n
        v = abs(total - left_sum)
        if v < m:
            m = v
    return m
