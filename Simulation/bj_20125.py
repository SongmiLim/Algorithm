# 20125 쿠키의 신체측정
"""
머리는 심장 바로 윗 칸:  x-1
왼쪽팔은 심장 바로 왼쪽: while(y-1)
오른쪽팔은 심장 바로 오른쪽: while(y+1)
허리는 심장 바로 아래쪽: while(x+1)
왼쪽다리는 허리의 왼쪽 아래: whie(x+1), y-1
오른쪽 다리는 허리는 왼쪽 아래: while(x+1), y+1

출력
심장위치
왼쪽팔 오른쪽팔 허리 왼쪽다리 오른쪽다리
"""

def solve():
  result = []
  # 머리 위치
  flag = False
  for i in range(N):
    for j in range(N):
      if graph[i][j] == '*':
        head_x, head_y = i, j
        flag = True
        break
    if flag:
      break
  
  # 심장 위치
  heart_x, heart_y = head_x+1, head_y

  
  # 왼팔 위치
  cnt = 1
  larm_x, larm_y = heart_x, heart_y-1
 
  while 0<=larm_y<N:
    if larm_y-1<0 or graph[larm_x][larm_y-1] != '*':
      break
    larm_y-=1
    cnt+=1
    
  result.append(cnt)
  
  # 오른팔 위치
  cnt = 1
  rarm_x, rarm_y = heart_x, heart_y+1

  while 0<=rarm_y<N:  
    if rarm_y+1>=N or graph[rarm_x][rarm_y+1] != '*':
      break
    rarm_y+=1
    cnt+=1

  result.append(cnt)

  # 허리 위치
  cnt = 1
  back_x, back_y = heart_x+1, heart_y
  
  while 0<=back_x<N:  
    if graph[back_x+1][back_y] != '*':
      break
    back_x+=1
    cnt+=1

  result.append(cnt)
  
  # 왼쪽다리 위치
  cnt = 1
  lleg_x, lleg_y = back_x+1, back_y-1

  while 0<=lleg_x<N:  
    if lleg_x+1 >=N or graph[lleg_x+1][lleg_y] != '*':
      break
    lleg_x+=1
    cnt+=1

  result.append(cnt)
  
  # 오른쪽다리 위치
  cnt = 1
  rleg_x, rleg_y = back_x+1, back_y+1

  while 0<=rleg_x<N-1:  
    if graph[rleg_x+1][rleg_y] != '*':
      break
    rleg_x+=1
    cnt+=1

  result.append(cnt)

  return heart_x+1, heart_y+1, result

if __name__ == "__main__":
  N = int(input())
  graph = [list(input()) for _ in range(N)]
  
  heart_x, heart_y, result = solve()
  
  print(heart_x, heart_y)
  print(' '.join(map(str, result)))
 