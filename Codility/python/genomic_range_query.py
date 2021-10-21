def solution(S, P, Q):
	# We just need to check the variance in the letters
	# If we see that A changed first, we will return 1, if C changed first, return 2
	# If is G, return 3, if is T return 4

	# Initialize the 4 arrays first
	dict_nuc = {
		'A': [0]*len(S),
		'C': [0]*len(S),
		'G': [0]*len(S),
		'T': [0]*len(S)	
	}
	list_min = []
	# Now we sum the values everytime the letter appear
	# O(n)
	for i in range(len(S)):
		for key in dict_nuc.keys():
			if S[i] == key:
				if i > 0:
					dict_nuc[key][i] = dict_nuc[key][i-1] + 1
				else:
					dict_nuc[key][i] = 1
			else:
				if i > 0:
					dict_nuc[key][i] = dict_nuc[key][i-1]

	print(dict_nuc)

	# Find the min for each interval
	for i in range(len(P)):
		start = P[i]
		end = Q[i]

		i = 1
		if start == end:
			for key in dict_nuc.keys():
				if dict_nuc[key][start] == 1:
					list_min.append(i)
					break
				i+=1
		else:
			for key in dict_nuc.keys():
				if dict_nuc[key][start] < dict_nuc[key][end]: # It means there is a occurence of the letter in the interval
					list_min.append(i)
					break
	return list_min



