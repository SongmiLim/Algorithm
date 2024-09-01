#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long solve(std::vector<int>& rank_list) {
	long long level_of_dissatisfaction = 0;

	sort(rank_list.begin(), rank_list.end());
	for (int i = 0; i < rank_list.size(); i++) {
		level_of_dissatisfaction+=abs(rank_list[i] - (i + 1));
	}
	return level_of_dissatisfaction;
}

int main() {
	int n;
	std::vector<int> rank_list;

	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int rank;
		std::cin >> rank;
		rank_list.push_back(rank);
	}

	std::cout<<solve(rank_list);
	
	return 0;
}