#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {

	int n;
	std::cin >> n;
	std::unordered_map<std::string, std::string> map;
	std::vector<std::string> answer;

	for (int i = 0; i < n; i++) {
		std::string name, status;
		std::cin >> name;
		std::cin >> status;

		map[name] = status;
	}
	
	for (auto elem : map) {
		if (elem.second != "leave") {
			answer.push_back(elem.first);
		}
	}

	sort(answer.rbegin(), answer.rend());

	for (auto elem : answer) {
		std::cout << elem << "\n";
	}

	return 0;
}