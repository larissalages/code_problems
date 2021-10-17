def solution(S, P, Q):
	l_min = []
	map_nuc = {'A':1, 'C':2, 'G':3, 'T':4}
	for m in range(len(P)):
		min_ = 5
		sub_S = S[P[m]:Q[m]+1]
		for s in sub_S:
			if map_nuc[s] == 1:
				min_ = 1
				break
			if map_nuc[s] < min_:
				min_ = map_nuc[s]
		l_min.append(min_)

	return l_min


