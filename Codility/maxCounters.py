def solution(N, A):
    counters = [0]*(N+1)
    max_ = 0
    for i in A:
        if i == N+1:
            for j in range(1, len(counters)):
                counters[j] = max_
        else:
            counters[i] += 1
            if counters[i] > max_:
                max_ = counters[i]
    del counters[0]
    return counters
