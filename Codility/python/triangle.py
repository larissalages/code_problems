# The condition shows that between the three numbers, two of them always have to have the sum grather than the one left
# So we just need to order and check if the two first numbers have sum grther than the third one
def solution(A):
    A.sort()
    for i in range(len(A)-2):
        if A[i] + A[i+1] > A[i+2]:
            return 1
    return 0
