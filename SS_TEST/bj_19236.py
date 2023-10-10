# 19236 청소년 상어
"""
position의 배열은 범위가 0부터 시작함에 유의,, 
이거때문에 시간을 엄청 잡아먹었다
"""
import copy
import sys

max_score = 0
def dfs(shark_x, shark_y, score, t_board):
  global max_score
  score += t_board[shark_x][shark_y][0]
  max_score = max(score, max_score)
 
  t_board[shark_x][shark_y][0] = 0  # 상어 위치 set
  
  # 물고기 move
  move_fish(shark_x, shark_y, t_board)

  # 상어 move
  shark_pos = t_board[shark_x][shark_y][1]
  
  for i in range(1, 5):
    nx = shark_x + dx[shark_pos]*i
    ny = shark_y + dy[shark_pos]*i
    
    if (0<=nx<4 and 0<=ny<4) and t_board[nx][ny][0]>0:    # t_board[][][0] == 0일때는 상어가 위치할 때
      dfs(nx, ny, score, copy.deepcopy(t_board))


def move_fish(shark_x, shark_y, t_board):
  for i in range(1, 17):    # 1~16번의 fish
    # 물고기가 있는지의 여부 확인  => 상어에게 먹혔을 수 있다
    fish_x, fish_y = -1, -1
    for j in range(4):
      for k in range(4):
        if t_board[j][k][0] == i:
          fish_x, fish_y = j, k
          break
          
    if fish_x==-1 and fish_y==-1:
      continue
    fish_pos = t_board[fish_x][fish_y][1]
    
    # 물고기를 가야 할 방향으로 이동
    for r in range(8):
      npos = (fish_pos+r) % 8
      nx = fish_x + dx[npos]
      ny = fish_y + dy[npos]
      
    # 보드 범위를 벗어나거나 상어와 같은 위치일 때 다시 회전
      if not (0<=nx<4 and 0<=ny<4) or (nx == shark_x and ny == shark_y):
        continue

      t_board[fish_x][fish_y][1] = npos
      t_board[fish_x][fish_y], t_board[nx][ny] = t_board[nx][ny], t_board[fish_x][fish_y]
      break
      
if __name__ == "__main__":
  board = [[] for _ in range(4)]
  result = 0
  dx = [-1, -1, 0, 1, 1, 1, 0, -1]
  dy = [0, -1, -1, -1, 0, 1, 1, 1]
  
  for i in range(4):
    data = list(map(int, input().split()))
    for j in range(0, 8, 2):   # 파이썬의 문법 이용 원래는 2*i, 2*i+1-1 이런식
      board[i].append([data[j], data[j+1]-1])
    
  x, y = 0, 0   # 상어의 처음 위치
  fish_idx, fish_position = board[0][0][0], board[0][0][1]
  
  dfs(x, y, 0, board)
  print(max_score)