// 11047: 동전 0

#include <iostream>

int main()
{
  int N, K;
  int cnt = 0;
  std::cin >> N >> K;

  int money_list[11];

  for (int i = 0; i < N; i++) {
    int money;
    std::cin >> money;
    money_list[i] = money;
  }

  for (int i = N-1; i >= 0; i--) {
    while (money_list[i] <= K) {
      cnt++;
      K -= money_list[i];
      if (K == 0) break;
    }

  }
  std::cout << cnt;
  return 0;
}