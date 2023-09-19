from collections import deque

def BFS(graph, root):
  visited = []
  queue = deque([root])

  while queue:
    n = queue.popleft()
    if n not in visited:
      visited.append(n)
      next_visit = list(set(graph[n]) - set(visited))
      next_visit.sort()
      queue += next_visit
  return visited


if __name__ == "__main__":
  n, m, r = map(int, input().split())
  graph = {}

  for i in range(m):
    u, v = map(int, input().split())

    if u not in graph:
      graph[u] = [v]
    elif v not in graph[u]:
      graph[u].append(v)

    # 양방향 간선이므로, 양쪽에 추가
    if v not in graph:
      graph[v] = [u]
    elif u not in graph[v]:
      graph[v].append(u)

print(DFS(graph, r))
