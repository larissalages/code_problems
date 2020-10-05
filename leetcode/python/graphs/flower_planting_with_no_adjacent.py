# You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

# paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

# Also, there is no garden that has more than 3 paths coming into or leaving it.

# Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

# Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.
class Solution:
	def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
		graph = [[] for i in range(N)]
		garden = [0] * N
		l_flowers = [1,2,3,4]
		# create the graph
		for i, j in paths:
			graph[i-1].append(j-1)
			graph[j-1].append(i-1)
		for i in range(N):			
			l_used = []
			for j in graph[i]:
				l_used.append(garden[j])
			flower =  (set(l_flowers) - set(l_used)).pop()
			garden[j] = flower

		return garden
