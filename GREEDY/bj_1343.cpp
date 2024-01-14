// 1343: 폴리오미노

#include <iostream>

int main() {

  std::string board, result;
  int cnt = 0;

  std::cin >> board;

  //board += ' ';

  for (int i = 0; i < board.size(); i++) {
    if (board[i] == 'X') cnt++;

    if (board[i] == '.') {
      result += '.';
      if (cnt % 2 != 0) break;
      else cnt = 0;
    }

    if (board[i + 1] != 'X' && cnt == 2) {
      result += "BB";
      cnt = 0;
    }

    else if (cnt == 4) {
      result += "AAAA";
      cnt = 0;
    }

  }

  std::cout << (cnt%2 != 0 ? "-1" : result) << std::endl;

  return 0;
}