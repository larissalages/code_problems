from collections import deque


def solution(S):
    stack = deque()
    close_list = [')',']','}']
    d = {'(': ')', '[': ']', '{': '}'}
    for s in S:
        if s in d.keys(): # list of open characters 
            stack.append(s)
        elif s in close_list:
            value = stack.pop()
            if s != d.get(value):
                return 0
    return 1
