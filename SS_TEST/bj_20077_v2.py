# 20057 마법사 상어와 토네이도
"""
def main:
input()으로 모래의 양을 가진 graph를 받는다
magic_tornado() 실행

def magic_tornado(x, y):
x, y는 N//2

for i in range(1, N+1):
  if i % 2 != 0:  => 1, 3, 5, 7
    rotate(left, i)
    rotate(down, i)
  else:   => 2, 4, 6
    rotate(right, i)
    rotate(up, i)
    
def rotate(position, cnt)    
  rate = {'left': left, 'down': down...}
  
  # 토네이도 좌표 업데이트
  왼쪽일 때: i만큼 왼쪽으로
  아래일 때: .....
  
  # 그래프에 있는 모래양에 해당 비율만큼 모래 추가
    if, 그래프 밖을 벗어날 때 result++
    else, 전체 모래 양 - 벗어난 양을 현재 자리에 누적
    
  
  
"""
def magic_tornado(x, y):
  # left&down 1, right&up 2, left&down 3 ,,,,,
  for i in range(1, N+1):
    if i %2 != 0:
      move(i, 0, -1, 'left')
      move(i, 1, 0, 'down')
    else:
      move(i, 0, 1, 'right')
      move(i, -1, 0, 'up')

def move(cnt, dx, dy, pos):
  global result
  global tornado_x, tornado_y
  
  # 토네이도 위치 업데이트
  for _ in range(cnt):
    tornado_x = tornado_x + dx
    tornado_y = tornado_y + dy
    a_x = tornado_x + dx*2
    a_y = tornado_y + dy*2
    if tornado_x<1 or tornado_y<1:
      break

  spreads = 0
  # 모래 흩날리기
  for i in range(5):
    for j in range(5):
      r = rate[pos][i][j]
      if r == 0:
        continue
      sand = int(graph[i][j]*r)

  rate[pos][a_x][a_y] = graph[tornado_nx][tornado_ny] - spreads  # 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양
    
    if 1<=nx or 1<=ny:
      result += sand  
    else:
      graph[nx][ny] += sand
    spreads += sand
      
      
def rotate(p):
  new_p = list(list(zip(*p))[::-1])
  return new_p

if __name__ == "__main__":
  N = int(input())

  graph = [list(map(int, input().split())) for _ in range(N)]

  left = [[0, 0, 0.02, 0, 0], [0, 0.1, 0.02, 0.01, 0], [0.05, 0, 0, 0, 0], [0, 0.1, 0.07, 0.01, 0], [0, 0, 0.02, 0, 0]]
  down = rotate(left)
  right = rotate(down)
  up = rotate(right)
  
  rate = {'left':left, 'right':right, 'up':up, 'down':down}    
  
  result = 0
  tornado_x, tornado_y = N//2, N//2
  tornado_x, tornado_y = N//2, N//2
  
  magic_tornado(tornado_x, tornado_y)