# 8979 올림픽
def score(list):
  list = sorted(list, key=lambda x:(x[1],x[2],x[3]))

  score = 1
  for i in range(N-1):
      if list[i][0] == K:
        return score
        
      if list[i][1] == list[i+1][1] and list[i][2] == list[i+1][2] and list[i][2] == list[i+1][2]:
        score = score
      else:
        score+=1
        
  return score
  
if __name__ == "__main__":
  N, K = map(int, input().split())
  list = []
  for _ in range(N):
    country_idx, gold, silver, bronze = map(int, input().split())
    list.append((country_idx, gold, silver, bronze))
  print(score(list))