class graph:
	def __init__(self, gdict=None):
		if gdict is None:
			gdict =[]
		self.gdict = gdict

	def getVertices(self):
		return list(self.gdict.keys())

	def getEdges(self):
		edges = []
		for vtx in self.gdict:
			for edg in self.gdict[vtx]:
				if {vtx, edg} not in edges:
					edges.append({vtx, edg})
		return edges

	def addVertex(self, vxt):
		if vxt not in self.gdict:
			self.gdict[vxt] = []

	def addEdge(self, edge):
		v1, v2 = tuple(edge)
		if v2 not in self.gdict[v1]:
			self.gdict[v1].append(v2)


graph_elements = { "a" : ["b","c"],
            "b" : ["a", "d"],
            "c" : ["a", "d"],
            "d" : ["e"],
            "e" : ["d"]
            }

g = graph(graph_elements)

g.addVertex('f')
g.addEdge({'a','e'})
print(g.getVertices())
print(g.getEdges())