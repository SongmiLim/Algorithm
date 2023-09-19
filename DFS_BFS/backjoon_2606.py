### 2606 virus
import sys
sys.setrecursionlimit(10**9)

def DFS(root):
  visited[root] = True
  result.append(root)

  for adj_node in graph[root]:
    if not visited[adj_node]:
      DFS(adj_node)
  return


if __name__ == "__main__":
  com_count = int(input())  # 컴퓨터 수
  net_count = int(input())  # 네트워크 상에서 연결된 컴퓨터 쌍의 수
  graph = [[] for _ in range (com_count+1)]
  #visited = [False for _ in range(com_count)]
  visited = [False] * (com_count+1)
  result = []
  
  for _ in range(net_count):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

  root = 1
  DFS(root)
  print(len(result)-1)
  
