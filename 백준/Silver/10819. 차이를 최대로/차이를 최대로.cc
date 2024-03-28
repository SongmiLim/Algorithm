#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


///// sol1. 백트래킹 사용 /////
// 1-1 방문 배열 사용//
int max_sum = 0;
int N;
vector <int> num_list;
vector <int> v;
bool visited[8] = { false, };

void solve() {
	if (v.size() == N) {
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			sum += abs(v[i + 1] - v[i]);
		}
		max_sum = max(max_sum, sum);

		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(num_list[i]);
			solve();
			v.pop_back();
			visited[i] = false;
		}
	}
}

// 1-2 swap 사용 //
/*void solve(int len) {
	if (len == N) {
		int sum = 0;
		for (int i = 0; i < num_list.size() - 1; i++) {
			sum += abs(num_list[i + 1] - num_list[i]);
		}
		max_sum = max(max_sum, sum);
		return;
	}
	for (int i = len; i < N; ++i) {
		swap(num_list[len], num_list[i]);
		solve(len + 1);
		swap(num_list[len], num_list[i]);
	}
}*/

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}

	// solve(0);
	solve();

	cout << max_sum;
	return 0;
}

/*       
////// sol2. 순열 사용 //////
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		num_list.push_back(num);
	}
	sort(num_list.begin(), num_list.end());

	do {
		int sum = 0;
		for (int i = 0; i < num_list.size() - 1; i++) {
			sum += abs(num_list[i + 1] - num_list[i]);
		}
		max_sum = max(max_sum, sum);

	} while (next_permutation(num_list.begin(), num_list.end()));

	cout << max_sum;
	return 0;
}
*/