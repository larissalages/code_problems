class Node:
    def __init__(self, value, neighbors={}):
        self.value = value
        self.neighbors = neighbors

    def add_neighbor(self, neighbor_v, weight):
        self.neighbors[neighbor_v] = weight


class Graph:
    def __init__(self):
        self.vertices = []

    def get_vertex(self, value):
        for v in self.vertices:
            if v.value == value:
                return v

    def vertex_already_exist(self, vtx):
        find_vertex = [True for x in self.vertices if x.value == vtx]
        if any(find_vertex) is False:
            return False
        else:
            return True

    def add_vertex(self, value):
        n = Node(value)
        self.vertices.append(n)
        return n

    def add_edge(self, vtx1, vtx2, weight):
        node1 = self.get_vertex(vtx1)
        if node1 is None:
            node1 = self.add_vertex(vtx1)
        node2 = self.get_vertex(vtx2)
        if node2 is None:
            node2 = self.add_vertex(vtx2)

        node1.add_neighbor(vtx2, weight)
        node2.add_neighbor(vtx1, weight)

    def print(self):
        for v in self.vertices:
            print('{}: {}'.format(v.value, v.neighbors))
