#include <iostream>

int main() {
  int H, W, N, M;
  std::cin >> H >> W >> N >> M;

  int r = (W % (M + 1) == 0) ? W / (M + 1) : W / (M + 1) + 1;
  int c = (H % (N + 1) == 0) ? H / (N + 1) : H / (N + 1) + 1;
  int result = r * c;
  std::cout << result;

  return 0;
}