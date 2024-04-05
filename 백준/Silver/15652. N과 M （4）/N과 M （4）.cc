#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> num_list;
bool visited[9];

void solve(int idx, int cnt) {
	if (cnt == M) {
		for (auto& a : num_list) {
			cout << a << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (!visited[i]) {
			num_list.push_back(i);
			solve(i, cnt + 1);
			num_list.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	solve(1, 0);

	return 0;
}