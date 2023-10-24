# 5073 삼각형과 세 변

if __name__ == "__main__":
  a, b, c = -1, -1, -1

  while True:
    
    a, b, c = map(int, input().split())
    max_num = max(a, b, c)

    if a==0 and b==0 and c==0:
      break
      
    if max_num >= (a+b+c-max_num):
      print("Invalid")
      
    elif a==b and b==c and c==a:
      print("Equilateral")
  
    elif a==b or b==c or c==a:
      print("Isosceles")
  
    elif a!=b and b!=c and c!=a:
      print("Scalene")
  
    