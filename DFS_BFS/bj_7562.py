# 7562 나이트의 이동 
"""
queue에 시작 위치 추가
queue에서 방문할 위치 popleft()
if, 방문할 위치가 도착 위치와 같으면
count 리턴   => graph[x][y]
else,
if 갈 수 있는 모든 위치 중 방문하지 않았던 곳일 경우
count +1 해준다  => graph[x][y] + 1
queue에 추가해준다
"""

from collections import deque

def bfs(src_x, src_y, dst_x, dst_y):
  queue = deque()
  queue.append((src_x, src_y))

  while queue:
    x, y = queue.popleft()

    if x == dst_x and y == dst_y:
      result.append(graph[x][y])
      return
      
    for i in range(8):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx<0 or nx>=I or ny<0 or ny>=I:   # 그래프 범위를 벗어나면 건너뜀
        continue
        
      elif graph[nx][ny] == 0:
        graph[nx][ny] = graph[x][y] +1
        queue.append((nx, ny))

if __name__ == "__main__":
  dx = [-2, -1, 1, 2, 2, 1, -1, -2]
  dy = [1, 2, 2, 1, -1, -2, -2, -1]
  result = []
  
  T = int(input())
  for _ in range(T):
    I = int(input())
    src_x, src_y = map(int, input().split())
    dst_x, dst_y = map(int, input().split())
    graph = [[0 for _ in range(I+1)] for _ in range(I+1)]
    bfs(src_x, src_y, dst_x, dst_y)

  for i in result:
    print(i)