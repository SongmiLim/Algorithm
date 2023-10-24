# 2292 벌집
"""
1: 1     0
2~7: 2   6
8~19: 3  12 
20~37: 4 18
38~ 
"""

if __name__ == "__main__":
  n = int(input())

  cnt = 1
  while True:
    if n <= 1 :
      break
    n = n - 6*cnt
    cnt+=1
  print(cnt)
    