#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> num_list;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}

	sort(num_list.begin(), num_list.end());
	int max_sum = 0;

	do {
		int sum = 0;
		for (int i = 0; i < num_list.size()-1; i++) {
			sum += abs(num_list[i + 1] - num_list[i]);
		}
		max_sum = max(max_sum, sum);

	} while (next_permutation(num_list.begin(), num_list.end()));
	
	cout << max_sum;
	return 0;
}