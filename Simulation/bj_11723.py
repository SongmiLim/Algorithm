"""
런타임 에러   => 예외처리 안해줘서...  
set()에서 remove()사용 시 해당 아이템이 집합에 없을경우 런타임에러 발생, discard() 사용 시 에러 없이 안전하게 지울 수 있음
시간 초과   => readine으로 받아야 함
별거 아닌 문제였지만, 에러가 굉장히 많이 났다
"""

# 11723 집합
import sys
input = sys.stdin.readline

def remove(x):
  if x not in num_set:
    return
  num_set.remove(x)

def check(x):
  if x in num_set:
    print(1)
  else:
    print(0)

def toggle(x):
  if x in num_set:
    num_set.remove(x)
  else:
    num_set.add(x)

def all():
  for i in range(1,21):
    num_set.add(i)

if __name__ == "__main__":
  M = int(input())
  num_set = set()

  for i in range(M):
    line = list(map(str, input().split()))
    if len(line)>1:
      x = int(line[1])

    command = line[0]
    if command == "add":
      num_set.add(x)
    elif command == "remove":
      remove(x)
    elif command == "check":
      check(x)
    elif command == "toggle":
      toggle(x)
    elif command == "all":
      all()
    elif command == "empty":
      num_set.clear()