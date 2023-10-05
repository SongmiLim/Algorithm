# 5014 스타트링크
"""
예외 처리의 중요성.. 을 보여주는 문제
만약 방문하려는 층이 해당 층과 같을 경우 예외 처리를 해줘야한다 ㄷㄷ
u와 d가 0일수도 있기 때문
"""
from collections import deque

def bfs():
  queue = deque()
  queue.append(s)
  
  while queue:
    floor = queue.popleft()
    
    if floor == g:
      print(visited[floor])
      return
      
    for i in move:
      nfloor = floor + i 
      
      if nfloor <1 or nfloor>f:
        continue
        
      if nfloor == floor:
        continue

      if visited[nfloor] == 0:
        queue.append(nfloor)
        visited[nfloor] = visited[floor] + 1
  print("use the stairs")    
  

if __name__ == "__main__":
  f, s, g, u, d = map(int, input().split())
  visited = [0] * (f+1)
  move = [u, -d]
  bfs()