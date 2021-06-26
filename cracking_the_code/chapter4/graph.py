class Node:
    def __init__(self, value):
        self.value = value
        self.neighbors = {}

    def add_neighbor(self, neighbor, weight=0):
        self.neighbors[neighbor] = weight

    def get_connections(self):
        l = []
        for n in self.neighbors:
            l.append(n.value)
        return l


class Graph:
    def __init__(self):
        self.vertices = {}

    def get_vertex(self, value):
        if value in self.vertices:
            return self.vertices[value]
        else:
            return None

    def add_vertex(self, value):
        n = Node(value)
        self.vertices[value] = n
        return n

    def add_edge(self, vtx1, vtx2, weight):
        if vtx1 not in self.vertices:
            vtx1 = self.add_vertex(vtx1)
        if vtx2 not in self.vertices:
            vtx2 = self.add_vertex(vtx2)
        self.vertices[vtx1].add_neighbor(self.vertices[vtx2], weight)
        self.vertices[vtx2].add_neighbor(self.vertices[vtx1], weight)

    def get_vertices(self):
        return self.vertices.keys()

    def print(self):
        for v in self.vertices:
            print('{}: {}'.format(v, self.vertices[v].get_connections()))
