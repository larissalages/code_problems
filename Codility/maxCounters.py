def solution(N, A):
    counters = [0]*(N+1)
    max_counter = 0
    max_current = 0
    for i in A:
        if 1 <= i <= N:
            if max_counter > counters[i-1]:
                counters[i-1] = max_counter
            counters[i-1] += 1
            if counters[i-1] > max_current:
                max_current = counters[i-1]
        else:
            max_counter = max_current

    for i in range(len(counters)):
        if max_counter > counters[i]:
             counters[i] = max_counter

    return counters
