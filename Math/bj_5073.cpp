#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<std::string> result_list;

  while (1) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int max_val = std::max({ a, b, c });

    if (a == 0 && b == 0 && c == 0)
      break;

    if (a == b && b == c && c==a)
      result_list.push_back("Equilateral");
    else if(a+b+c - max_val <= max_val)
      result_list.push_back("Invalid");
    else if (a == b or b == c or c == a)
      result_list.push_back("Isosceles");
    else if (a != b != c)
      result_list.push_back("Scalene");
  }
  for (std::string result : result_list)
    std::cout << result << std::endl;
  return 0;
}