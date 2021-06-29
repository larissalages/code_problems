from graph import Graph
from collections import deque


def search_bfs(start, end):
    if start == end:
        return True
    q = deque()
    q.append(start)

    while q:
        node = q.popleft()
        node.visited = True
        for ngb in node.neighbors:
            if node == end:
                return True
            if ngb.visited is False:
                node.visited = True
                q.append(ngb)
    return False


def main():
    g = Graph()
    g.add_vertex('a')
    g.add_vertex('b')
    g.add_vertex('c')
    g.add_vertex('d')
    g.add_vertex('e')
    g.add_vertex('f')
    g.add_edge('a', 'b', 2)
    g.add_edge('a', 'c', 1)
    g.add_edge('a', 'd', 3)
    g.add_edge('b', 'd', 2)
    g.add_edge('c', 'e', 1)
    g.print()
    node1 = g.get_vertex('a')
    node2 = g.get_vertex('e')
    print(search_bfs(node1, node2))
    node1 = g.get_vertex('a')
    node2 = g.get_vertex('f')
    print(search_bfs(node1, node2))


if __name__ == '__main__':
    main()
