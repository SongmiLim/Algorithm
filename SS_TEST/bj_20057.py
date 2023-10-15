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
def magic_tornado(N, x, y):
  # left&down 1, right&up 2, left&down 3 ,,,,,
  for i in range(0, N):
      if i % 2 == 0:
          move(i, 0, -1, 'left')
          move(i, 1, 0, 'down')
      else:
          move(i, 0, 1, 'right')
          move(i, -1, 0, 'up')


def move(cnt, dx, dy, pos):
  global result
  global tornado_x, tornado_y

  for _ in range(cnt):
      # 토네이도 위치 업데이트
      tornado_x += dx
      tornado_y += dy

      if tornado_x < 0 or tornado_y < 0:
          break

      # 모래 흩날리기
      spreads = 0
      for move_dx, move_dy, r in rate[pos]:
          nx, ny = tornado_x + move_dx, tornado_y + move_dy

          if r == 0:
              sand = graph[tornado_x][tornado_y] - \
                  spreads  # 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양
          else:
              sand = int(graph[tornado_x][tornado_y] * r)

          # 모래 더해주기
          if 0 <= nx < N and 0 <= ny < N:  # 범위 안에 있을 땐 해당 칸에 있는 모래에 더해주기
              graph[nx][ny] += sand
          else:                # 범위 밖으로 나갔을 땐 result에 더해주기
              result += sand
          spreads += sand


if __name__ == "__main__":
  N = int(input())

  graph = [list(map(int, input().split())) for _ in range(N)]

  # left = [[-2, 0, 0.02], [2, 0, 0.02], [-1, -1, 0.1], [1, 1, 0.01], [-1, 0, 0.07],
  #         [1, 0, 0.07], [-1, 1, 0.01], [1, 1, 0.01], [0, -2, 0.05], [0, -1, 0]]  # 마지막에 a도 넣어줘야한다
  left = [(-2, 0, 0.02), (2, 0, 0.02), (-1, -1, 0.1), (-1, 0, 0.07), (-1, 1, 0.01),
          (1, -1, 0.1), (1, 0, 0.07), (1, 1, 0.01), (0, -2, 0.05), (0, -1, 0)]
  down = [(-y, x, z) for x, y, z in left]
  right = [(-y, x, z) for x, y, z in down]
  up = [(-y, x, z) for x, y, z in right]

  rate = {'left': left, 'right': right, 'up': up, 'down': down}

  result = 0
  tornado_x, tornado_y = N//2, N//2

  magic_tornado(N, tornado_x, tornado_y)
  print(result)
