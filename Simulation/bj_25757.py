# 25757 임스와 함께하는 미니게임

def play_game():
  people_cnt = len(play_list) 
  if game_option == 'Y':
    return people_cnt//(Y_cnt-1)
  elif game_option == 'F':
    return people_cnt//(F_cnt-1)
  elif game_option == 'O':
    return people_cnt//(O_cnt-1)
  return


if __name__ == "__main__":
  N, game_option = input().split()
  Y_cnt, F_cnt, O_cnt = 2, 3, 4
  play_list = ['' for _ in range(int(N))]
  
  for i in range(int(N)):
    play_list[i] = input()
  play_list = set(play_list)
  print(play_game())