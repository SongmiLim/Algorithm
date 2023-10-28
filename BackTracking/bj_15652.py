# 15652 N과 M (4)

def dfs(start):
  
  if len(stack) == m:
    print(" ".join(map(str, stack)))
    return 
    
  for i in range(start, n+1):
      stack.append(i)
      dfs(i)
      stack.pop()

if __name__ == "__main__":
  n, m = map(int, input().split())
  stack = []
  visited= [0]*(n+1)
  dfs(1)