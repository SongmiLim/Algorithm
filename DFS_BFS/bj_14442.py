# 14442 벽 부수고 이동하기 2
from collections import deque

def bfs():
    queue = deque()
    queue.append((0, 0, 0))
    visited = [[[0] * (k + 1) for _ in range(m)] for _ in range(n)]
    visited[0][0][0] = 1

    while queue:
        crush, x, y = queue.popleft()

        if x == n - 1 and y == m - 1:
            return visited[x][y][crush]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            if graph[nx][ny] == 0 and visited[nx][ny][crush] == 0:
                queue.append((crush, nx, ny))
                visited[nx][ny][crush] = visited[x][y][crush] + 1

            if graph[nx][ny] == 1 and crush < k and visited[nx][ny][crush + 1] == 0:
                queue.append((crush + 1, nx, ny))
                visited[nx][ny][crush + 1] = visited[x][y][crush] + 1

    return -1

if __name__ == "__main__":
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    n, m, k = map(int, input().split())
    graph = [list(map(int, input().strip())) for _ in range(n)]

    result = bfs()
    print(result)
