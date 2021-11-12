# It scored 60% on codility, passed all correctness tests but failed on performance tests because is O(n^2)
def solution(A):
    min_avg = float("inf") 
    min_start = 0
    for p in range(len(A)):
        sum_ = A[p]
        len_ = 1
        for q in range(p+1,len(A)):
            sum_ = sum_ + A[q]
            len_ += 1
            avg = sum_/len_
            if avg < min_avg:
                min_avg = avg
                min_start = p

    return min_start
