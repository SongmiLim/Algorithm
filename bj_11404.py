# 11404 플로이드
"""
n의 범위가 n<=100   => 작다
'모든' 도시의 쌍에 대해서 필요한 비용의 최솟값 구하기   => 모든, 쌍, 최솟값 이므로 플로이드와샬 이용

"""
def floyd_warshall(graph):
  for r in range(n):
    graph[r][r] = 0
    
  for k in range(n):
    for i in range(n):
      for j in range(n):
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
  return graph
  

INF = int(1e8)
if __name__ == "__main__":
  n = int(input())
  m = int(input())
  graph = [[INF] * (n) for _ in range(n)]
  
  for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a-1][b-1] = min(graph[a-1][b-1], c)

  graph = floyd_warshall(graph)

  for i in range(n):
    for j in range(n):
      if graph[i][j] == INF:
        graph[i][j] = 0
        
  for i in range(n):
    print(' '.join(map(str, graph[i])))