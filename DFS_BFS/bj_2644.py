# 2644 촌수계산
import sys

def dfs(n, num):
  num += 1
  visited[n] = 1
  
  if n == v:
    result.append(num)
    return
    
  for i in graph[n]:
    if visited[i] == 0:
      dfs(i, num)


if __name__ == "__main__":
  n = int(input())
  u, v = map(int, input().split())
  m = int(input())
  graph = [[] for _ in range(n+1)]
  visited = [0] * (n+1)
  result = []
  num = 0
  
  for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)
    
  dfs(u, num)

  if len(result) == 0:
    print(-1)
  else:
    print(result[0]-1)