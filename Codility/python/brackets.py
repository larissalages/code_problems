from collections import deque


def solution(S):
    stack = deque()
    close_list = [')',']','}']
    d = {'(': ')', '[': ']', '{': '}'}
    for s in S:
        if s in d.keys(): # list of open characters 
            stack.append(s)
        elif s in close_list:
            if len(stack) > 0:
                value = stack.pop()
                if s != d.get(value):
                    return 0
            else:
                return 0
    return 1 if len(stack) == 0 else 0
