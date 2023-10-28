# 1205 등수 구하기
def solve():
  # 태수의 등수를 맨 마지막 등수로 init
  t_score = N+1
  
  if N == 0:
    return 1
    
  score_list = list(map(int, input().split()))
  
  # 리스트가 꽉 차있을 때 새로 들어온 점수가 제일 낮은 점수보다 작거나 같은 경우
  if N == P and s <= score_list[-1]:
      return -1
  
  # 등수 set 
  for i in range(N):
    if s >= score_list[i]:
      score_list[i] = s
      t_score = i + 1
      break
  return t_score

if __name__ == "__main__":
  N, s, P = map(int, input().split())
 
  print(solve())
  