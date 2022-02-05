def solution(A, B):
    
    stk = deque()
    n = 0
    # insert values in stack
    for i in range(len(A)-1, -1, -1):
        stk.append(i)
    if len(stk) > 0:
        p = stk.pop()
    while len(stk) > 0:
        q = stk.pop()
        if B[p] == 1 and B[q] == 0:
            if A[q] > A[p]:
                p = q
        else:
            n += 1
            p = q

    return n+1
