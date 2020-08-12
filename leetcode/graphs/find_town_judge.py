class Solution:
	def findJudge(self, N, trust):
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


s = Solution()
print(s.findJudge(2,[[1,2]]))
