from manim import *

vertices = [1, 2, 3, 4, 5, 6, 7, 8, 9]
edges = [
    (1, 2), (1, 3), (1, 4),
    (2, 1), (2, 5),
    (3, 1), (3, 6), (3, 7),
    (4, 1), (4, 8), (4, 9),
    (5, 2),
    (6, 3),
    (7, 3),
    (8, 4),
    (9, 4)
]

def color_vertex(g: Graph, idx: int, color: ParsableManimColor):
    return g.vertices[idx].animate.set_fill(color).add(MathTex(str(idx), color=BLACK).move_to(g.vertices[idx].get_center()))

def color_edge(g: Graph, e: tuple[int, int], color: ParsableManimColor):
    return g.edges[e].animate.set_fill(color)

def dfs(start_vertex: int, edges: list[tuple[int]], visited: list[int] = []) -> tuple[list[int], list[tuple[int, int]]]:
    newly_visited = []
    newly_visited.append(start_vertex)
    visited_edges = []
    for e in edges:
        if e[0] == start_vertex and e[1] not in newly_visited and e[1] not in visited:
            visited_edges.append(e)
            x = dfs(e[1], edges, visited + newly_visited)
            newly_visited += x[0]
            visited_edges += x[1]
    return newly_visited, visited_edges


def bfs(start_vertex: int, edges: list[tuple[int]]) -> tuple[list[int], list[tuple[int, int]]]:
    visited = []
    visited_edges = []
    next = []
    next.append(start_vertex)
    while len(next) > 0:
        node = next[0]
        next = next[1:]
        visited.append(node)
        for e in edges:
            if e[0] == node and e[1] not in visited and e[1] not in next:
                next.append(e[1])
                visited_edges.append(e)
    return visited, visited_edges

class DFS(Scene):
    def construct(self):
        g = Graph(vertices, edges, labels=True, layout="tree", root_vertex = 1, layout_scale=5, vertex_config={"radius": 0.5})
        visited, visited_edges = dfs(1, edges)

        self.add(g)
        for i in range(len(visited)):
            self.play(color_vertex(g, visited[i], RED))
            if i < len(visited_edges):
                self.play(color_edge(g, visited_edges[i], RED))
        self.wait()

class BFS(Scene):
    def construct(self):
        g = Graph(vertices, edges, labels=True, layout="tree", root_vertex = 1, layout_scale=5, vertex_config={"radius": 0.5})
        visited, visited_edges = bfs(1, edges)

        self.add(g)
        for i in range(len(visited)):
            self.play(color_vertex(g, visited[i], RED))
            if i < len(visited_edges):
                self.play(color_edge(g, visited_edges[i], RED))
        self.wait()