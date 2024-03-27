# 15649 N과 M (1)
"""
dfs를 이용해서 풀이했다
주어진 노드만큼 돌면서 방문 하지 않았을 경우,
방문 처리 후 스택에 추가
dfs() 로 재귀
"""
def dfs():
  
  if len(stack) == m:
    print(" ".join(map(str, stack)))
    return 
    
  for i in range(1, n+1):
    if visited[i] == 0:
      visited[i] = 1
      stack.append(i)
      dfs()
      stack.pop()
      visited[i] = 0

if __name__ == "__main__":
  n, m = map(int, input().split())
  stack = []
  visited= [0]*(n+1)
  dfs()