"""
reversed(list)와 list[::-1]  은 같다
"""


def rotate_90(p):
  #new_p = list(list(zip(*reversed(p))))
  new_p = list(list(zip(*p[::-1])))
  print(new_p)
  
def rotate_reverse_90(p):
  #new_p = list(reversed(list(zip(*p))))
  new_p = list(list(zip(*p))[::-1])
  print(new_p)

if __name__ == "__main__":
  
  array = [[1,2,3,4,5,6], [7,8,9,10,11,12], [13,14,15,16,17,18] ,[19,20,21,22,23,24]]
  
  rotate_90(array)
  rotate_reverse_90(array)