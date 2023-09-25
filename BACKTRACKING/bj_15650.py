# 15650 N과 M (2)

def dfs():
  
  if len(stack) == m:
    print(" ".join(map(str, stack)))
    return 
    
  for i in range(1, n+1):
    if i not in stack:
      stack.append(i)
      dfs()
      stack.pop()

if __name__ == "__main__":
  n, m = map(int, input().split())
  stack = []
  visited= [0]*(n+1)
  dfs()