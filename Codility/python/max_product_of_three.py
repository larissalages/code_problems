def find_max(A):
    max_ = float('-inf')
    for i in range(len(A)):
        if A[i] > max_:
            max_ = A[i]
            idx = i
    del A[idx]
    return max_, A
        

def solution(A):
    lst_max = []
    for i in range(3):
        value, A = find_max(A)
        lst_max.append(value)
    return lst_max[0]*lst_max[1]*lst_max[2]
