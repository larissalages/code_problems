def solution(A):
    map_ = {}
    for v in A:
        if v not in map_:
            map_[v] = 1
        else:
            map_[v] += 1

    for key in map_:
        if map_[key] % 2 != 0:
            return key

# Using xor operation
def solution(A):
    res = 0
    for n in A:
        res ^= n
    return res