def DFS(root):
  visited[root] = True
  path.append(root)
  
  for adj_node in graph[root]:
    if not visited[adj_node]:
      DFS(adj_node)


if __name__ == "__main__":
  n, m, r = map(int, input().split())
  graph = [[] for _ in range(n+1)]
  path = []
  result = [0 for _ in range(n)]
  visited = [False]*(n+1)
  print(result)
  for _ in range(m):
    u, v = map(int, input().split())

    graph[u].append(v)
    # 양방향 간선이므로, 양쪽에 추가
    graph[v].append(u)

  for i in graph:
    i.sort()
  
  DFS(r)
  
  print(path)