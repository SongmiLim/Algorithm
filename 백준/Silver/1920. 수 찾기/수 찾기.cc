#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;
vector<int> compare_nums;
vector<int> result;

void Solve() {
	sort(nums.begin(), nums.end());
	for (auto& compare_num : compare_nums) {
		if (binary_search(nums.begin(), nums.end(), compare_num)) {
			result.push_back(1);
		}
		else {
			result.push_back(0);
		}
	}

	for (auto& num : result) {
		cout << num << "\n";
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int compare_num;
		cin >> compare_num;
		compare_nums.push_back(compare_num);
	}

	Solve();

	return 0;
}