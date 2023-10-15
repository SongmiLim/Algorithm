# 13460 구슬탈출 2
from collections import deque

def bfs(rx, ry, bx, by):
    queue = deque()
    queue.append((rx, ry, bx, by, 1))

    visited[rx][ry][bx][by] = 1
    # visited_r[rx][ry] = 1
    # visited_b[bx][by] = 1

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
                    
            # if visited_r[nrx][nry] == 0 or visited_b[nbx][nby] == 0:
            if visited[nrx][nry][nbx][nby] == 0:
                # chance += 1     # 이렇게 해주면 테케중에 에러나는게 있다. 왤까...
                queue.append((nrx, nry, nbx, nby, chance+1))
                # visited_r[nrx][nry] = 1
                # visited_b[nbx][nby] = 1
                visited[nrx][nry][nbx][nby] = 1
    return -1


def move(x, y, dx, dy):
    # 다음 위치가 갈수 있는 위치면 계속 감
    count = 0
    # 조건 주어지는 게 핵심이다 다음 가야할 곳이 벽이 아닐 때 계속 움직이지만
    # 그러면 구멍을 지나칠 수 있으니 나의 위치가 구멍일 땐 빠져나온다
    # == "." 으로 조건을 줘도 되지만 다음 위치가 'O'인지 '#'인지 여부를 확인하느
    # 조건을 더 줘야한다
    while board[x+dx][y+dy] != "#" and board[x][y] != 'O': 
        x += dx
        y += dy
        count += 1
    return x, y, count


if __name__ == "__main__":

    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    n, m = map(int, input().split())

    board = [list(input()) for _ in range(n)]
    # visited_r = [[0]*m for _ in range(n)]
    # visited_b = [[0]*m for _ in range(n)]
    visited = [[[[0]*m for _ in range(n)] for _ in range(m)] for _ in range(n)]

    rx, ry, bx, by = [0] * 4
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                rx, ry = i, j
            elif board[i][j] == 'B':
                bx, by = i, j

    print(bfs(rx, ry, bx, by))
