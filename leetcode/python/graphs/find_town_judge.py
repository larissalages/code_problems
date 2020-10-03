# In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

# If the town judge exists, then:

# The town judge trusts nobody.
# Everybody (except for the town judge) trusts the town judge.
# There is exactly one person that satisfies properties 1 and 2.
# You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

# If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

class Solution1:
	def findJudge(self, N, trust):
		if N ==1: return N
		graph = {}
		for pair in trust:
			p1 = pair[0]
			p2 = pair[1]

			if p1 not in graph:
				graph[p1] = []
			graph[p1].append(p2)

			if p2 not in graph:
				graph[p2] = []

		poss_judge = None
		for key in graph.keys():
			if not graph[key]: poss_judge = key

		if poss_judge is None: return -1

		for key in graph.keys():
			if poss_judge not in graph[key] and key!= poss_judge: return -1

		return poss_judge

# A MUCH better approach
class Solution2:
	def findJudge(self, N, trust):
		count = [0] * (N+1)
		for i, j in trust:
			count[i] -= 1
			count[j] += 1
		for i in range(1, N+1):
			if count[i] == N-1:
				return i
		return -1


s = Solution1()
print(s.findJudge(2,[[1,2]]))
