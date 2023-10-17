# 2579 계단 오르기
"""
연속해서 3계단은 오를 수 없다
n번째 계단은 반드시 밟아야한다

1. 전 칸 밟고 마지막 칸 밟는 경우
dp(n) = dp(n-1) + dp(n) 
주의!! 이 경우에는 전전칸을 밟으면 안된다
dp(n) = dp(n-3) + score(n-1) + score(n)

2. 전전칸 밟고 마지막 칸 밟는 경우
dp(n) = dp(n-2) + score(n)
"""

def solve():
  dp[0] = score_list[0]
  dp[1] = max(score_list[0] + score_list[1], score_list[1]) 
  dp[2] = max(score_list[0] + score_list[2], score_list[1] + score_list[2])

  for i in range(3, n):
    dp[i] = max((dp[i-3] + score_list[i-1] + score_list[i]), dp[i-2] + score_list[i])
  
if __name__ == "__main__":
  n = int(input())
  score_list = [0] * (n+1)
  
  for i in range(n):
    s = int(input())
    score_list[i] = s

  dp = [0]*(n+1)
  solve()
  print(dp[n-1])