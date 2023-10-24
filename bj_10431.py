# 10431 줄세우기
def solve(s_list):
  move = 0
  for i in range(1, len(s_list)-1):
    for j in range(1, len(s_list)-1):
      if s_list[j] > s_list[j+1]:
        temp = s_list[j]
        s_list[j]=s_list[j+1]
        s_list[j+1] = temp

        move += 1
  return move 

  
  return move
if __name__ == "__main__":
  
  P = int(input())
  for i in range(1, P+1):
    student_list = list(map(int, input().split()))
    print(i, solve(student_list))