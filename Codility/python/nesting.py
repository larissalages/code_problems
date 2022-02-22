from collections import deque

def solution(S):
	map_char = {'(': ')'}
	stk = deque()

	for char in S:
		s = stk.pop() if len(stk) > 0 else None
		if map_char.get(s) != char:
			if s is not None:
				stk.append(s)
			stk.append(char)

	if len(stk) == 0:
		return 1
	else:
		return 0
