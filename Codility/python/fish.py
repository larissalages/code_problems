from collections import deque

def solution(A, B): 
    n = 0
    stk1 = deque()
    stk2 = deque()
    # insert values in stack
    for i in range(len(A)-1, -1, -1):
        stk1.append(i)

    if len(stk1) > 0:
        p = stk1.pop()
    else:
        return 0
    if len(stk1) > 0:
        q = stk1.pop()
    else:
        return 1

    while True:
        if not (B[p] == 1 and B[q]==0):
            stk2.append(p)
            p = q
            if len(stk1) > 0:
                q = stk1.pop()
            else:
                break
        else:
            if A[q] > A[p]:
                if len(stk2) > 0:
                    p = stk2.pop()
                else:
                    break
            else:
                if len(stk1) > 0:
                    q = stk1.pop()
                else:
                    break
    return len(stk2) + 1 
