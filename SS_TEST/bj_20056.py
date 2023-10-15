"""
변수 i, j, k 사용에 유의하자 
특히 반복문 안에 있을 경우 i 중복 사용에 유의!!!!!!
"""

# 20056 마법사 상어와 파이어볼

  def magic_shark():
      # 파이어볼 이동
      while fireballs:
          _r, _c, _m, _s, _d = fireballs.pop(0)

          nr = (_r + dx[_d]*_s) % N  # 1번 행, 열과 N번 행, 열은 연결되어있다
          nc = (_c + dy[_d]*_s) % N
          graph[nr][nc].append([_m, _s, _d])

      # 이동 끝난 후 파이어볼의 개수에 따라 조건 주기
      for i in range(N):
          for j in range(N):
              if len(graph[i][j]) > 1:   # 해당 좌표에 파이어볼 2개 이상일 경우
                  sum_m, sum_s, cnt_even, cnt_odd, cnt_fireball = 0, 0, 0, 0, len(
                      graph[i][j])

                  while graph[i][j]:
                      _m, _s, _d = graph[i][j].pop(0)
                      sum_m += _m
                      sum_s += _s
                      if _d % 2 == 0:
                          cnt_even += 1
                      else:
                          cnt_odd += 1

                  change_m = sum_m//5
                  change_s = sum_s//cnt_fireball
                  if cnt_even == cnt_fireball or cnt_odd == cnt_fireball:
                      nd = [0, 2, 4, 6]
                  else:
                      nd = [1, 3, 5, 7]

                  if change_m == 0:
                      continue

                  # for i in range(4):
                  #     fireballs.append([i, j, change_m, change_s, nd[i]])   # 이 부분때문에 계속 틀렸다. 왤까   => 변수 i가 위에서 이미 사용되어서 그렇다.. 

                  for d in nd:
                      fireballs.append([i, j, change_m, change_s, d])

              elif len(graph[i][j]) == 1:
                  _m, _s, _d = graph[i][j].pop()
                  fireballs.append([i, j, _m, _s, _d])


  if __name__ == "__main__":
      N, M, K = map(int, input().split())

      dx = [-1, -1, 0, 1, 1, 1, 0, -1]
      dy = [0, 1, 1, 1, 0, -1, -1, -1]

      fireballs = []
      graph = [[[] for _ in range(N)] for _ in range(N)]

      for _ in range(M):
          data = list(map(int, input().split()))
          fireballs.append([data[0], data[1], data[2], data[3], data[4]])

      for _ in range(K):
          magic_shark()

      # sum_fireballs = 0
      # for f in fireballs:
      #     sum_fireballs += f[2]

      # print(sum_fireballs)

      print(sum([fireball[2] for fireball in fireballs]))
