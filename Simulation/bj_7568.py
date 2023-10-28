# 7568 덩치
def huge_score(p_list):
  score_list = []  
  
  for i in range(len(p_list)):
    count = 0
    for j in range(len(p_list)):
      if p_list[i][0] < p_list[j][0] and p_list[i][1] < p_list[j][1]:
        count+=1
    score_list.append(count+1)
  
  return score_list
  
if __name__ == "__main__":
  N = int(input())
  p_list = [list(map(int, input().split())) for _ in range(N)]
  
  print(' '.join(map(str, huge_score(p_list))))
  