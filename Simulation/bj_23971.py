#23971 ZOAC 4
import math

def solve():
  col = math.ceil(W/(M+1))
  row = math.ceil(H/(N+1))
  
  return col * row

if __name__ == "__main__":
  H, W, N, M = map(int, input().split())
  
  print(solve())
