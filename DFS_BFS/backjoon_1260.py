### 1260 DFS와 BFS

from collections import deque
import sys
sys.setrecursionlimit(10**9)


def BFS(root):
  bfs_visited[root] = True
  queue = deque([root])

  while queue:
    n = queue.popleft()
    bfs_result.append(n)
    
    for adj_node in graph[n]:
      if not bfs_visited[adj_node]:
        queue.append(adj_node)
        bfs_visited[adj_node] = True


def DFS(root):
  dfs_visited[root]=True
  dfs_result.append(root)
  
  for adj_node in graph[root]:
    if not dfs_visited[adj_node]:
      DFS(adj_node)
  return

if __name__ == "__main__":
  n, m, r = map(int, input().split())
  graph = [[] for _ in range(n+1)]
  dfs_visited = [False] * (n+1)
  bfs_visited = [False] * (n+1)
  dfs_result = []
  bfs_result = []
  
  for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
  
  for i in graph:
    i.sort()
  
  DFS(r)
  print(" ".join(map(str, dfs_result)))
  BFS(r)
  print(" ".join(map(str, bfs_result)))