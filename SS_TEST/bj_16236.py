# 16236 아기 상어
"""
  1초에 상하좌우로 한칸씩 이동  => dx, dy
  
  아기상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없음  
  => if graph[nx][ny] <= shark_size,   
  자신과 크기가 같거나 작은 물고기 있을 경우 '조건'에 따라 먹음 => eat_list 필요
  1. 먹을 수 있는 물고기 >= 1: 거리가 가장 가까운 물고기 먹기  => 최단거리 => bfs 이용
  2. 가장 위에 있는 물고기(x-1) => 가장 왼쪽에 있는 물고기(y-1) 순으로 eat  => 정렬 사용

  아기상어는 자신의 크기와 같은 수의 물고기를 먹을때마다 크기가 1 증가
  => 처음에 물고기 2개 먹으면 shark_size = 3
  
  더이상 먹을 수 있는 물고기가 없다면 => return

"""
from collections import deque

def move_shark(x, y, shark_size):
    visited = [[0]*n for _ in range(n)]
    eat_list = []

    queue = deque()
    queue.append((x, y))
    visited[x][y] = 1

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue

            if visited[nx][ny] == 0:
                if graph[nx][ny] <= shark_size:
                    queue.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1

                    if 0 < graph[nx][ny] < shark_size:
                        eat_list.append((nx, ny, visited[nx][ny]-1))
                      
    return sorted(eat_list, key=lambda x: (x[2], x[0], x[1]))


if __name__ == "__main__":
    n = int(input())
    graph = [list(map(int, input().split())) for _ in range(n)]

    dx = [-1, 1, 0, 0]  # 상하좌우
    dy = [0, 0, -1, 1]

    # 처음 상어가 있는 위치
    for i in range(n):
        for j in range(n):
            if graph[i][j] == 9:
                x = i
                y = j

    count = 0
    result = 0
    shark_size = 2

    while True:
        shark = deque(move_shark(x, y, shark_size))

        if len(shark) == 0:
            break

        nx, ny, distance = shark.popleft()
        result += distance

        # 상어가 먹은 물고기와 상어가 있던 자리를 0으로 초기화
        graph[x][y], graph[nx][ny] = 0, 0

        # 상어의 위치를 다음 위치로 업데이트
        x, y = nx, ny

        # 상어가 먹은 물고기 수 추가
        count += 1

        # 상어가 먹은 물고기 수와 상어의 사이즈가 같으면 사이즈 ++, 물고기 수는 0으로 init
        if count == shark_size:
            shark_size += 1
            count = 0

    print(result)
