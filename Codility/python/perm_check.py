def solution(A):
    counter = {}
    for num in range(1,len(A)+1):
        counter[num] = 0
    for num in A:
        if num in counter:
            counter[num] += 1
            if counter[num] > 1:
                return 0
        else:      
            return 0
    return 1

A = [4, 1, 3, 2]
solution(A)
