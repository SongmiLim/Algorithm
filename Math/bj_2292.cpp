#include <iostream>

int main() {
  int N;
  int cnt = 0;
  std::cin >> N;

  while (1) {
    N -= cnt * 6;
    cnt++;

    if (N <=1)
      break;
  }
  std::cout << cnt;
  return 0;
}