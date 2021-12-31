# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    coords = []
    for i in range(len(A)):
        coords.append([i-A[i], i+A[i]])

    n_pairs = 0
    for i in range(len(coords)):
        a = coords[i][0]
        b = coords[i][1]
        for j in range(i+1, len(coords)):
            c = coords[j][0]
            d = coords[j][1]
            if c <= a <= d or c <= b <= d or a <= c <= b or a <= d <= b:
                n_pairs += 1
            
    return n_pairs
