# 13460 구슬탈출 2
"""
visited를 4차원 배열이 아닌 list로 할당한다
visited = []
visited.append((x, y, ~))

visited 여부 확인 시 
if (x, y ~) not in visited:

이 방법이 배열 초기화 시 더 편하다
"""
from collections import deque


def bfs(rx, ry, bx, by):
    queue = deque()
    queue.append((rx, ry, bx, by, 1))
    visited.append((rx, ry, bx, by))


    while queue:
        rx, ry, bx, by, chance = queue.popleft()

        if chance > 10:
            break

        # move
        for i in range(4):
            nrx, nry, r_count = move(rx, ry, dx[i], dy[i])
            nbx, nby, b_count = move(bx, by, dx[i], dy[i])
            # if nrx<0 or nbx<0 or nry<0 or nby<0 or nrx>=n or nbx>=n or nry>=m or nby>=m:
            #   continue

            if board[nbx][nby] == 'O':
                continue

            if board[nrx][nry] == 'O':
                return chance

            if nrx == nbx and nry == nby:
                if r_count > b_count:
                    nrx -= dx[i]
                    nry -= dy[i]
                else:
                    nbx -= dx[i]
                    nby -= dy[i]

            if (nrx, nry, nbx, nby) not in visited:
                queue.append((nrx, nry, nbx, nby, chance+1))
                visited.append((nrx, nry, nbx, nby))
    return -1


def move(x, y, dx, dy):
    count = 0
    while board[x+dx][y+dy] != "#" and board[x][y] != 'O':  # 조건 설정이 핵심
        x += dx
        y += dy
        count += 1
    return x, y, count


if __name__ == "__main__":

    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    n, m = map(int, input().split())

    board = [list(input()) for _ in range(n)]
    visited = []

    rx, ry, bx, by = [0] * 4
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                rx, ry = i, j
            elif board[i][j] == 'B':
                bx, by = i, j

    print(bfs(rx, ry, bx, by))
