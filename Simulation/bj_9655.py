# 9655 돌게임

if __name__ == "__main__":
  N = int(input())

  cnt = 0  # cnt가 홀수이면 상근 승, 짝수이면 창영 승
  while N>0:
    if N-3>=0:
      N = N-3
      cnt+=1
    else:
      N = N-1
      cnt+=1
  print("SK") if cnt%2 ==1 else print("CY")