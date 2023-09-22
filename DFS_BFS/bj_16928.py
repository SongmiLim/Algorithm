# 16928 뱀과 사다리 게임
"""
dictionary를 사용하면 쉽게 풀린다
"""

from collections import deque

def bfs():
  queue = deque()
  queue.append(1)

  while queue:
    x = queue.popleft()
    
    if x==100:
      return graph[x]
    
    for nx in range(x+1, x+7):
      # if, 방문하지 않았다면
      # if, 위치가 사다리 or 뱀에 해당하면 다음칸으로 이동 
      # 이동한 칸의 방문 횟수 추가, 다음 이동할 칸으로 추가(queue)
      
      if nx > 100:
        continue
      
      if nx in have_ladder.keys():
        nx = have_ladder[nx]
          
      if nx in have_snake.keys():
        nx = have_snake[nx]
        
      if graph[nx] == 0:
        graph[nx] = graph[x] + 1
        queue.append(nx)
            
if __name__ == "__main__":
  n, m = map(int, input().split())
  graph = [0] * 101
  
  have_ladder = {}
  have_snake = {}

  for _ in range(n):
    a, b = map(int, input().split())
    have_ladder[a] = b
  
  for _ in range(m):
    a, b = map(int, input().split())
    have_snake[a] = b

  print(bfs())