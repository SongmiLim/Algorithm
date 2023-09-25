# 1707 이분 그래프
"""
이분 그래프란? 모든 꼭짓점을 서로 다른 색으로 칠하되, 모든 변이 서로 다른 색의 꼭짓점을 포함하는 그래프
한 변의 양 꼭짓점은 서로 색이 달라야한다
한마디로 u에 빨간색, v에 파란색
그래프 순회 중, u와 v가 같은색이면 False
"""

from collections import deque
import sys

def bfs(start):
  queue = deque()
  queue.append(start)
  visited[start] = 1
  
  while queue:
    n = queue.popleft()
      
    for adj_node in graph[n]:
      if visited[adj_node] == 0:
        if visited[n] == 1:
          visited[adj_node] = 2
        elif visited[n] == 2:
          visited[adj_node] = 1
        queue.append(adj_node)
    
def check_bipartite_graph(graph):
  for i in range(1, total_v):
    for j in graph[i]:
      if visited[i] == visited[j]:
        return "NO"
  return "YES"

if __name__ == "__main__":
  k = int(sys.stdin.readline())
  result = []
  
  for _ in range(k):
    total_v, e = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(total_v+1)]
    visited = [0] * (total_v + 1) 
    
    # 그래프 정보 입력
    for _ in range(e):
      u, v = map(int, sys.stdin.readline().split())
      graph[u].append(v)
      graph[v].append(u)
    
    # 모든 노드 탐색
    for i in range(1, total_v):
      if visited[i] == 0:
        bfs(i)
    result.append(check_bipartite_graph(graph))

  print("\n".join(result))